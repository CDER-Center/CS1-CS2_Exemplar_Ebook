import multiprocessing as mp
import time
import matplotlib.pyplot as plt

def work(n):
    s = 0
    for i in range(n):
        s += i*i
    return s

def run(p, tasks=8, n=2_000_000):
    start = time.perf_counter()
    with mp.Pool(p) as pool:
        pool.map(work, [n] * tasks, chunksize=1)
    return time.perf_counter() - start

if __name__ == "__main__":
    cores = [1, 2, 4, 8]
    times = []

    for p in cores:
        t = run(p)
        times.append(t)
        print(f"cores={p} time={t:.3f}")

    # Metrics
    t1 = times[0]
    speedup = [t1 / t for t in times]
    efficiency = [s / p for s, p in zip(speedup, cores)]

    # Plots
    plt.figure()
    plt.plot(cores, times, marker='o')
    plt.xlabel("Cores")
    plt.ylabel("Runtime (s)")
    plt.title("Runtime vs Cores")
    plt.show()

    plt.figure()
    plt.plot(cores, speedup, marker='o')
    plt.xlabel("Cores")
    plt.ylabel("Speedup")
    plt.title("Speedup vs Cores")
    plt.show()

    plt.figure()
    plt.plot(cores, efficiency, marker='o')
    plt.xlabel("Cores")
    plt.ylabel("Efficiency")
    plt.title("Efficiency vs Cores")
    plt.show()
