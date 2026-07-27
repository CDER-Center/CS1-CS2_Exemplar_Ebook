
#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>  (e.g., -fopenmp)

// Parallel Odd-Even Sort implementation
void parallelOddEvenSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // The algorithm requires up to n total phases to guarantee sorting
    for (int phase = 0; phase < n; ++phase) {
        
        // Phase 0, 2, 4... -> Even Phase (pairs: 0-1, 2-3, 4-5...)
        // Phase 1, 3, 5... -> Odd Phase  (pairs: 1-2, 3-4, 5-6...)
        if (phase % 2 == 0) {
            // Parallelize the even-indexed pairs loop
            #pragma omp parallel for shared(arr, n)
            for (int i = 0; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                }
            }
        } else {
            // Parallelize the odd-indexed pairs loop
            #pragma omp parallel for shared(arr, n)
            for (int i = 1; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
}

int main() {
    // Sample unsorted array
    // Speed up will not show because the data size, 
    // should use a much bigger data size
    std::vector<int> data = {34, 7, 23, 32, 5, 62, 78, 4, 0, 11, 99, 14};
    
    std::cout << "Original_Array:";
    for (int num : data) std::cout << num << ",";
    std::cout << "\n";

    // Run parallel sort
    parallelOddEvenSort(data);

    std::cout << "Sorted_Array:";
    for (int num : data) std::cout << num << ",";
    std::cout << "\n";

    return 0;
}