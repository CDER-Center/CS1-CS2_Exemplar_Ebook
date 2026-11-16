import multiprocessing as mp
import time
import numpy as np

N = 40_000_000          # large array (~320 MB)
PROCS = 4               # increase on multi-socket machines

# -------- BAD: memory initialized in main process --------
def bad_worker(a_slice):
    # read-heavy access to remote memory
    return np.sum(a_slice * 2.0)

def bad_case():
    a = np.ones(N, dtype=np.float64)   # first-touch happens HERE (single core)
    chunks = np.array_split(a, PROCS)

    with mp.Pool(PROCS) as p:
        return sum(p.map(bad_worker, chunks))


# -------- GOOD: first-touch inside each worker --------
def good_worker(start_end):
    start, end = start_end
    a = np.ones(end - start, dtype=np.float64)  # local first-touch
    return np.sum(a * 2.0)

def good_case():
    step = N // PROCS
    tasks = [(i * step, (i + 1) * step) for i in range(PROCS)]

    with mp.Pool(PROCS) as p:
        return sum(p.map(good_worker, tasks))


def time_it(fn):
    t0 = time.perf_counter()
    fn()
    return time.perf_counter() - t0


if __name__ == "__main__":
    tb = time_it(bad_case)
    tg = time_it(good_case)

    print(f"BAD (remote memory): {tb:.3f}s")
    print(f"GOOD (local memory): {tg:.3f}s")
