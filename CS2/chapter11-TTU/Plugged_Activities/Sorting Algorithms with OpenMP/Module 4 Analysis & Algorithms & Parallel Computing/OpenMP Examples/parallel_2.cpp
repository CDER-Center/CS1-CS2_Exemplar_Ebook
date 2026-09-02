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
	cout << "The operating system schedules the threads arbitrarily, so "
	     << "whichever thread reaches cout first will print first. "
		 << "So although it looks like the thread IDs were assigned out of "
		 << "order when this program prints, they werent.\n\n";
    #pragma omp parallel
    {
		int tid = omp_get_thread_num();
		string print = "Hello from thread " + to_string(tid) + "\n";
		
		// The following #pragma will guard the output with a critical section 
		// which means this code can only be executed by one thread at a time. All other threads
		// trying to enter this "critical" region must wait until the thread inside finishes.
		// This prevents race conditions when multiple threads try to update or print to 
		// the same resource (like cout)
		#pragma omp critical (io)
		cout << print;
		
        #pragma omp for
        for (unsigned int i = 0; i < data.size(); i++) {
            data[i] += static_cast<int>(omp_get_thread_num());  // Add thread ID to each element
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
