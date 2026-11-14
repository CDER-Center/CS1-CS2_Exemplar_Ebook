import multiprocessing

def func (i):
    print(f'called func in process {i}')

if __name__ == '__main__':
    processed_jobs = []
    for i in range (5):
        p = multiprocessing.Process(target=func, args=(i,))
        processed_jobs.append(p)
        p.start()
        p.join()