import numpy as np
import time
import multiprocessing as mp

# Prepare data
np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[30000, 6])
data = arr.tolist()

#to be used with paralleization
def findmin(row):
    min = row[0]
    for n in row:
        if min > n:
            min = n
    return min

if __name__ == '__main__':
    pool = mp.Pool(mp.cpu_count())
    results = pool.map(findmin, [row for row in data])
    pool.close()

    final_result = findmin(results)
    print(final_result)
