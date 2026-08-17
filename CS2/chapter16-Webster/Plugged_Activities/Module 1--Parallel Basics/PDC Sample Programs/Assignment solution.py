import numpy as np
import time
import multiprocessing as mp

# Prepare data
np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[200000, 5])
data = arr.tolist()
print(data[:5])



''''#with paralleization
if __name__ == '__main__':

    #pool = mp.Pool(mp.cpu_count())
    pool = mp.Pool(5)

    results = pool.map(findmin, [row for row in data])

    pool.close()

    print(results)'''


'''# Solution Without Paralleization

def howmany_within_range(row, minimum, maximum):
    """Returns how many numbers lie within `maximum` and `minimum` in a given `row`"""
    count = 0
    for n in row:
        if minimum <= n <= maximum:
            count = count + 1
    return count

results = []
for row in data:
    results.append(howmany_within_range(row, minimum=4, maximum=8))

print(results[:10])'''

# Redefine, with only 1 mandatory argument.
def howmany_within_range_rowonly(row, minimum=4, maximum=8):
    count = 0
    for n in row:
        if minimum <= n <= maximum:
            count = count + 1
    return count
#results = pool.map(howmany_within_range_rowonly, [row for row in data])

#to be used with paralleization
def findmin(row):
    min = row[0]
    for n in row:
        if min > n:
            min = n
    return min

#without paralleization:
def findmin_2D(nums):
    min = nums[0][0]
    for row in nums:
        for n in row:
            if min > n:
                min = n
    return min

def calcsum(row):
    total = 0
    for n in row:
        total += n
    return total

if __name__ == '__main__':
    start = time.time()
    pool = mp.Pool(mp.cpu_count())
    results = pool.map(findmin, [row for row in data])
    pool.close()

    final_result = findmin(results)
    print(final_result)
    end = time.time()
    print('total time with paralleization', end - start)

    start = time.time()
    results_serial = findmin_2D(data)
    print(results_serial)
    end = time.time()
    print('total time with serialization', end - start)


    pool = mp.Pool(mp.cpu_count()) #time consuming
    start = time.time()
    total = pool.map(calcsum, [row for row in data])
    end = time.time()
    pool.close()
    finaltotal = calcsum(total)

    print(finaltotal)
    print('total time with paralleization', end - start)

    start = time.time()
    total = 0
    for row in data:
        total += calcsum(row)
    end = time.time()
    print(total)
    print('total time with serialization', end - start)
