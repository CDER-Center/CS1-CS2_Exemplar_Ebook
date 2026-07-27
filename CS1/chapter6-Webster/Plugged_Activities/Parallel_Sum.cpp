#include <iostream>
#include <vector>
#include <omp.h>

// Sequential summation
int sequentialSum(const std::vector<int>& data)
{
    int sum = 0;

    for (int value : data)
    {
        sum += value;
    }

    return sum;
}

// Parallel summation using OpenMP
int parallelSum(const std::vector<int>& data)
{
    int sum = 0;

    // reduction gives each thread a private copy of sum
    // and combines the partial sums at the end.
    #pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < static_cast<int>(data.size()); ++i)
    {
        sum += data[i];
    }

    return sum;
}

int main()
{
    std::vector<int> data = {
        34, 7, 23, 32, 5, 62,
        78, 4, 0, 11, 99, 14
    };

    int sequentialResult = sequentialSum(data);
    int parallelResult = parallelSum(data);

    std::cout << "Sequential sum: " << sequentialResult << '\n';
    std::cout << "Parallel sum:   " << parallelResult << '\n';

    if (sequentialResult == parallelResult)
    {
        std::cout << "The results match.\n";
    }
    else
    {
        std::cout << "Error: the results do not match.\n";
    }

    return 0;
}