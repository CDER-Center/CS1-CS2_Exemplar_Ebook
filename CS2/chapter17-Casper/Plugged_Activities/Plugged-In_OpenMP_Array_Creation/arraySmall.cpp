/* This code is useful for looking at the thread ids and seeing how the 
workload is distributed.  The cout line is commented out, but uncommenting this can
lead to a demonstration of what happens when a bunch of threads are attempting to access the
terminal at the same time -- the output becomes all jumbled up.  This is because std::cout is not
thread safe and lacks atomicity for the chained << operators.  The fix is to use printf since this is 
thread safe in most libraries*/

#include <iostream>
#include <omp.h>
#include <chrono>
#include <thread>
using namespace std;

int main()
{

        const long long SIZE = 50;
        cout << "Number of processors: " << thread::hardware_concurrency() << endl;

        long long *arrptr = nullptr; 
        arrptr = new long long[SIZE];

        #pragma omp parallel for
        for (long long ind = 0; ind < SIZE; ind++)
        {
                int id = omp_get_thread_num();
                //cout << "ind " << ind << "    id: " << id << endl;
                printf("id: %d    ind: %lld    &ind %p\n", id, ind, (void*)&ind);
                arrptr[ind] = ind;
        }

        cout << "**************************" << endl;
        for (long long ind = 0; ind < SIZE; ind++)
        {
                cout << "ind: " << ind << "     value: " << arrptr[ind] << endl;
        }

        return 0;
}
