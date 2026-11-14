import numpy as np
import time

N = 30_000_000
a = np.random.rand(N).astype(np.float64)

def time_it(fn, reps=3):
    ts = []
    for _ in range(reps):
        t0 = time.perf_counter()
        fn()
        ts.append(time.perf_counter() - t0)
    return sorted(ts)[1]

# Memory-bound: single pass over a (mostly bandwidth)
def mem_bound():
    return np.sum(a)

# More compute per element: extra arithmetic work (higher intensity)
def compute_bound():
    x = a
    for _ in range(20):          # increase this to make it "more compute"
        x = x * 1.0000001 + 0.0000003
    return np.sum(x)

tm = time_it(mem_bound)
tc = time_it(compute_bound)

print(f"memory-bound sum:      {tm:.4f}s")
print(f"compute-heavier loop:  {tc:.4f}s")
