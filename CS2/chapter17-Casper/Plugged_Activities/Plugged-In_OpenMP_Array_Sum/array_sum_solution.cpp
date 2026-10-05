/* fixing the problem by adding parallel region and #pragma omp critical */


#include <iostream>
#include <cmath>
#include <chrono>
#include <climits>  //only covers integers 
#include <limits>   //covers integers and floating point 
#include <omp.h>
using namespace std; 

int main(void){

    /* uses the sizeof() operator */
    cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(long long) << endl;
    /* uses the climits header */
    cout << LONG_MAX << " " << LONG_MIN << " " << LLONG_MAX <<  " " << LLONG_MIN << endl;
    /* uses the limits header */
    cout << numeric_limits<long>::max() << " " << numeric_limits<long>::min() << " ";
    cout << numeric_limits<long long>::max() << " " << numeric_limits<long long>::min() << endl; 
    long long int N = 100000000;

    long long int * array = new long long int[N];  //declare array of size N
    long long int i;

    /* chrono header
     * steady clock - monotonic always moving forward
     * system clock - calendar time, can be adjusted
     * high res clock - most precise, may alias either steady or system clock
     */

    auto start = chrono::steady_clock::now();
    
    //populate array
    # pragma omp parallel for
    for (i = 0; i < N; i++) {
        array[i] = i+1;
    }

    auto end = chrono::steady_clock::now();
    auto duration = end - start;
    auto ms = chrono::duration_cast<chrono::milliseconds>(duration);
    printf("Done populating %lld elements!\n", N);
    cout << "Time to fill array: " << ms.count() << " ms" << endl; 

    printf("Summing elements together...\n");
    long long sum = 0;

    auto start2 = chrono::steady_clock::now();

    #pragma omp parallel  //denotes start of a parallel region 
    {

            long long int partialSum = 0; 
    
            #pragma omp for 
            for (long long int j = 0; j < N; j++) {
                partialSum += array[j]; //each thread computes a local sum
            }

            #pragma omp critical // this code can only be used by one thread at a time
            {
                    sum += partialSum;  
            }

    }
    cout << "sum is " << sum << endl;
    long long int actualSum = (N + 1) * (N) / 2; 
    cout << "sum should be " << actualSum << endl;;
    auto end2 = chrono::steady_clock::now();
    auto duration2 = end2 - start2;
    auto ms2 = chrono::duration_cast<chrono::milliseconds>(duration2);
    cout << "Time for summing: " << ms2.count() << " ms" << endl; 

    delete [] array;

    return 0;
}
