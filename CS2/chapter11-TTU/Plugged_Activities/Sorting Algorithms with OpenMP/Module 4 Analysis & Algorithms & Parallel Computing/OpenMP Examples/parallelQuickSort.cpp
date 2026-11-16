/*	
	Filename: parallelQuickSort.cpp
	Author: April Crockett
	Date: 7/4/2025
	Purpose: To demonstrate using OpenMP to parallelize the quick sort algorithm.
	
	Note: since Quick Sort uses the divide-and-conquer algorithm design technique,
	it is a great algorithm to be able to run in parallel.
	
	Credits: I got the list of 10000 movie titles for movies.txt from Kaggle at
	https://www.kaggle.com/datasets/moazeldsokyx/imdb-top-10000-movies-dataset
	
	I then copied the movie titles several times into movies.txt to get 60,000 titles
	to be able to demonstrate the real power of speed-up with large data sets when
	parallelizing a vector.
*/

#include <iostream>
#include <vector>			  // used to create and use vectors
#include <fstream>			  // used to read in from movies.txt
#include <parallel/algorithm> // used for sort function
#include <omp.h>              // used for __gnu_parallel and figma statements
#include <ctime>              // used for computing runtime
#include <thread>			  // used for calculating number of logical processors on computer
#include <cstdlib>            // used for random number generation
#include "parallelQuickSort.h"

using namespace std;

int main() 
{
	//create a vector to hold the movie titles
    vector<string> movies;
	
	//variables for calculating runtime
    clock_t tStart, tStop;
    double compute_time_p;
	
	//determine number of logical processors on your computer
	const auto processor_count = thread::hardware_concurrency();
	
    //Number of threads OpenMP will use. 
    int num_threads;
	
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;
	
	while(!cin || num_threads < 1 || num_threads > 500)
	{
		if(!cin) 
			cout << "\nOops! You didn't enter a number!\n";
		else 
			cout << "\nOops! You didn't enter a number between 1-500!\n";
		//clear the error state on the stream to make the ios::good bit true again
		cin.clear(); 
		//ignore (remove) everything in the keyboard buffer up through '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a number 1 - 500: ";
		cin >> num_threads;
	}		
	
    omp_set_dynamic(false);
    omp_set_num_threads(num_threads);
	
    readFromFile(movies, "movies.txt");
    
	cout << "SIZE: " << movies.size() << endl;
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;
	
	//************************************FIRST RUN SERIAL QUICK SORT
	
	//make sure the movies vector is NOT sorted first to get 
	//accurate runtime of algorithm with unsorted vector
    scramble(movies); 

	tStart = clock();
    serialQuickSort(movies, 0, movies.size() - 1);
    tStop = clock();
	
    compute_time_p = (double)(tStop - tStart) / CLOCKS_PER_SEC;
    cout << "\nSerial Quick Sort(int): " << compute_time_p << " seconds" << endl;

	//************************************NOW RUN PARALLEL QUICK SORT

	scramble(movies); //unsort the vector again

    tStart = clock();
	#pragma omp parallel
	{
		#pragma omp single
		parallelQuickSort(movies, 0, movies.size() - 1, 0);
	}
    tStop = clock();

    compute_time_p = (double)(tStop - tStart) / CLOCKS_PER_SEC;
    cout << "\nParallel Quick Sort(int): " << compute_time_p << " seconds" << endl;
    
   return 0; 
}


void readFromFile(vector<string>& v, string filename)
{
    ifstream file;
    string tmp;
    file.open(filename);
    while(getline(file,tmp))
    {
        v.push_back(tmp);
    }
    file.close();
}

void printVector(vector<string>& v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void scramble(vector<string>& v)
{
    int randomIndex;
    srand(time(0));
    for (unsigned int i = 0; i < v.size(); i++)
    {
        randomIndex = rand() % v.size();
		//cout << "randomIndex: " << randomIndex << " and swap " << v[i] << " and " << v[randomIndex] << endl;
        swap(v[i], v[randomIndex]);
		
    }
}

/*
	Function: partition()
	Purpose: this function is used for the Quicksort algorithm.
	A pivot location is determined. The code below selects the last
	element to be the pivot. Then, everything smaller than the pivot 
	is moved to the left of the pivot and everything 
	larger than the pivot is moved to the right of 
	the pivot. At the end of the funciton, the 
	pivot is in its final sorted spot.
	
	Note: this funciton is called by both the serial & parallel versions
	of quicksort
*/
int partition(vector<string>& v, int low, int high)
{
    string pivot = v[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void serialQuickSort(vector<string>& v, int low, int high) 
{
	int pivot = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot = partition(v, low, high); //returns sorted location of pivot
	serialQuickSort(v, low, pivot-1); //recursively sort low partition
	serialQuickSort(v, pivot+1, high); //recursively sort high partition
}

void parallelQuickSort(vector<string>& v, int low, int high, int depth)
{
    if (low < high)
    {
        int pivot = partition(v, low, high);//returns sorted location of pivot
        
		//only parallelize this function call if num items to sort is less than 10000
		#pragma omp task shared(v) if(high-low > 10000)
        parallelQuickSort(v, low, pivot - 1, depth + 1);//recursively sort low partition
        
        #pragma omp task shared(v) if(high-low > 10000)
        parallelQuickSort(v, pivot + 1, high, depth + 1);//recursively sort high partition
        
		/*
			For each recursive call, you're potentially creating new OpenMP tasks
			(if the recursion depth is less than 4). These tasks run in parallel, allowing 
			the left and right parts of the vector to be sorted concurrently.
			The line below (#pragma omp taskwait) ensures that:
			     -The current thread (which launched the tasks for the left and right
				  recursive calls) will wait for both of those tasks to finish before continuing.
				 -This is essential to avoid proceeding (or returning from the function)
				  before the recursive sorting is done.
		*/
        #pragma omp taskwait
    }
}