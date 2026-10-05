/* Solution to the array creation problem*/
#include <iostream>
#include <omp.h>
#include <chrono>
using namespace std;

int main()
{
        auto start = chrono::high_resolution_clock::now();

        const long long SIZE = 100000000;

        long long *arrptr = nullptr; 
        arrptr = new long long[SIZE];

        #pragma omp parallel for
        for (long long ind = 0; ind < SIZE; ind++)
        {
                arrptr[ind] = ind;
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> elapsed = end - start;

        cout << "This program took: " << elapsed.count() << " ms\n"; 
        return 0;
}
