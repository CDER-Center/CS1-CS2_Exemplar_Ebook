import os
import time
import argparse
import multiprocessing as mp
from statistics import median

# ---------- Work definition ----------
# We create a large list A and compute:
# sum((A[i] * i) % 97 for i in range(N))
#
# We'll compute it in chunks [start, end) so it is parallelizable.

A_GLOBAL = None  # used in optimized version (worker-local global)


def build_data(n: int) -> list[int]:
    # Deterministic data; cheap to generate; large enough to matter.
    # Keep values small-ish to avoid huge integer arithmetic cost.
    return [(i * 17 + 13) % 10_000 for i in range(n)]


def serial_compute(a: list[int]) -> int:
    s = 0
    for i, val in enumerate(a):
        s += (val * i) % 97
    return s


# ---------- Naïve parallel (BAD) ----------
# BAD idea 1: Send the big list 'a' to every task (pickling overhead)
# BAD idea 2: Too many tasks (tiny chunks) + chunksize=1 (scheduling overhead)

def chunk_sum_naive(args) -> int:
    a, start, end = args  # a is huge -> pickled & sent repeatedly
    s = 0
    for i in range(start, end):
        s += (a[i] * i) % 97
    return s


def parallel_naive(a: list[int], procs: int, chunk_len: int, chunksize: int) -> int:
    tasks = []
    n = len(a)
    for start in range(0, n, chunk_len):
        end = min(start + chunk_len, n)
        tasks.append((a, start, end))

    with mp.Pool(processes=procs) as pool:
        partials = pool.map(chunk_sum_naive, tasks, chunksize=chunksize)
    return sum(partials)


# ---------- Optimized parallel (GOOD) ----------
# Fix 1: Put big data in each worker once using initializer (avoid pickling repeatedly)
# Fix 2: Use bigger chunk_len (fewer tasks) + bigger chunksize

def init_worker(a: list[int]) -> None:
    global A_GLOBAL
    A_GLOBAL = a


def chunk_sum_opt(start_end) -> int:
    start, end = start_end
    a = A_GLOBAL  # worker-local global reference
    s = 0
    for i in range(start, end):
        s += (a[i] * i) % 97
    return s


def parallel_optimized(a: list[int], procs: int, chunk_len: int, chunksize: int) -> int:
    n = len(a)
    tasks = []
    for start in range(0, n, chunk_len):
        end = min(start + chunk_len, n)
        tasks.append((start, end))

    with mp.Pool(processes=procs, initializer=init_worker, initargs=(a,)) as pool:
        partials = pool.map(chunk_sum_opt, tasks, chunksize=chunksize)
    return sum(partials)


# ---------- Timing helpers ----------
def time_median(func, trials: int = 3) -> tuple[float, int]:
    times = []
    result = None
    for _ in range(trials):
        t0 = time.perf_counter()
        result = func()
        t1 = time.perf_counter()
        times.append(t1 - t0)
    return median(times), result


def main():
    parser = argparse.ArgumentParser(description="Parallel Overhead Lab: before/after multiprocessing optimization")
    parser.add_argument("--n", type=int, default=8_000_000, help="problem size (default: 8,000,000)")
    parser.add_argument("--procs", type=int, default=min(4, os.cpu_count() or 4), help="number of processes")
    parser.add_argument("--trials", type=int, default=3, help="timing trials (median-of-trials reported)")
    parser.add_argument("--naive_chunk_len", type=int, default=10_000, help="naive chunk length (small => many tasks)")
    parser.add_argument("--opt_chunk_len", type=int, default=500_000, help="optimized chunk length (bigger => fewer tasks)")
    parser.add_argument("--naive_chunksize", type=int, default=1, help="Pool.map chunksize for naive run")
    parser.add_argument("--opt_chunksize", type=int, default=8, help="Pool.map chunksize for optimized run")
    args = parser.parse_args()

    print("\n=== Parallel Overhead Lab ===")
    print(f"N={args.n:,}  procs={args.procs}  trials={args.trials}")
    print(f"naive: chunk_len={args.naive_chunk_len:,} chunksize={args.naive_chunksize}")
    print(f" opt : chunk_len={args.opt_chunk_len:,} chunksize={args.opt_chunksize}\n")

    # Build data once
    a = build_data(args.n)

    # SERIAL
    t_serial, r_serial = time_median(lambda: serial_compute(a), trials=args.trials)
    print(f"[SERIAL] median time: {t_serial:.4f}s   result={r_serial}")

    # NAIVE PARALLEL
    t_naive, r_naive = time_median(
        lambda: parallel_naive(a, args.procs, args.naive_chunk_len, args.naive_chunksize),
        trials=args.trials
    )
    print(f"[NAIVE ] median time: {t_naive:.4f}s   result={r_naive}")

    # OPT PARALLEL
    t_opt, r_opt = time_median(
        lambda: parallel_optimized(a, args.procs, args.opt_chunk_len, args.opt_chunksize),
        trials=args.trials
    )
    print(f"[OPT   ] median time: {t_opt:.4f}s   result={r_opt}")

    # Correctness check
    if not (r_serial == r_naive == r_opt):
        print("\nWARNING: Results mismatch! Something is wrong.")
    else:
        print("\nResults match ✅")

    # Speedup / efficiency for best parallel version
    best_tp = min(t_naive, t_opt)
    best_label = "NAIVE" if t_naive <= t_opt else "OPT"
    speedup = t_serial / best_tp
    efficiency = speedup / args.procs

    print(f"\nBest parallel version: {best_label}")
    print(f"Speedup S(p)=T1/Tp = {speedup:.3f}")
    print(f"Efficiency E(p)=S(p)/p = {efficiency:.3f}")


if __name__ == "__main__":
    # Required on Windows/macOS to avoid recursive process spawning issues
    mp.freeze_support()
    main()
