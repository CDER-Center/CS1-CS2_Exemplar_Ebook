/*	
	Filename: parallel_1.cpp
	Author: April Crockett
	Date: 6/6/2025
	Purpose: To demonstrate using OpenMP to parallelize code
*/

#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
	
    // Step 1: Create a vector with 100 elements
    vector<int> data(10000, 1);  // Fill with 1s

    // Step 2: Set number of threads and disable dynamic adjustment
    omp_set_dynamic(false);         // Don't let OpenMP override thread count
    omp_set_num_threads(10);        // We want exactly 10 threads

    // Step 3: Define a parallel region and operate on the vector
    #pragma omp parallel
    {
		cout << "Hello from thread " << omp_get_thread_num() << "\n";
		
        #pragma omp for
        for (int i = 0; i < data.size(); i++) {
			// Add thread ID to each element
            data.at(i) += static_cast<int>(omp_get_thread_num());  
        }
    }

    // Step 4: Print elements to see results
    cout << "After processing:\n";
    for (int i = 0; i < 10000; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
	
    return 0;
}
