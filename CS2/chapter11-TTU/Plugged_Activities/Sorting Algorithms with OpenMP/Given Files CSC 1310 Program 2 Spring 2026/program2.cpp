/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		program2.cpp
	Author: 		Eddie Gannod & April Crockett & PUT YOUR NAME HERE
	Last Updated:	PUT TODAYS DATE HERE
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#include <iostream>
#include <vector>				// used to create and use vectors
#include <fstream>
#include <parallel/algorithm> 	// used for sort function
#include <omp.h>              	// used for OpenMP directives
#include <ctime>             	// used for seeding randome number generator
#include <thread>				//used for calculating number of logical processors on computer
#include <cstdlib>           	// used for random number generation
#include <chrono>				//used for measuring elapsed time
#include "program2.h"

using namespace std;

int main() 
{
	//create two vectors	
    vector<int> nums;       	
    vector<string> words;  		
	string filename;
	bool success;
    
	//determine number of logical processors on your computer
	const auto processor_count = thread::hardware_concurrency();
	
    //Number of threads OpenMP will use. 
    int num_threads;
	
	//ask the user for the number of threads
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;
	
	//*********************LOOK!************************************************
	//add in the code to validate the user's input
	//make sure the user entered in an integer 1 through 500 (and that they actually entered in an integer)
	
	omp_set_dynamic(false);
    omp_set_num_threads(num_threads);
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;
	
	//read from files & place in vectors
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(wordsSmall.txt or wordsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(words, filename);	
	} while(!success);
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(numsSmall.txt or numsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(nums, filename);
	} while(!success);
	cout << "SIZE of words: " << words.size() << endl;
	cout << "SIZE of nums: " << nums.size() << endl;
	
	//prior to calling any of the sort algorithms, you need to scramble (unsort) the vectors
	scramble(nums);
    scramble(words);
	/*************************************************************************Parallel Sort in Algorithm Library*****************************
	
	 * For more information about this algorithm in particular, take a look at 
	 * https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
	 * It uses the IntroSort algorithm, which is a hybrid between Quicksort, Heapsort,
	 * and Insertion Sort.
     *********************************************************************************/
	
	//****************************Parallel Sort in Algorithm Library*****************************/
    auto start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(nums.begin(), nums.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "\n<parallel/algorithm> library sort(int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(words.begin(), words.end());
    end = chrono::high_resolution_clock::now();
    cout << "<parallel/algorithm> library sort(words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


    /*********************************************************************************
		BUBBLE SORT
		
		First, scramble the two vectors (call the scramble function)
		Start the clock
		Call the bubbleSort function here for nums vector
		Stop the clock
		Compute the runtime (see example above)
		Print out result to screen
		
		Start the clock
		Call the bubbleSort function for the words vector
		Stop the clock
		Compute the runtime
		Print out result to screen.
		
     *********************************************************************************/
	 
	 
	/*********************************************************************************
		PARALLEL BUBBLE SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelBubbleSort function
     *********************************************************************************/


    /*********************************************************************************
		MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		mergeSort function
     *********************************************************************************/


    /*********************************************************************************
		PARALLEL MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelMergeSort function
     *********************************************************************************/


    return 0; 
}


/*********************************************************
 * HELPER FUNCTIONS
 * These functions help read in the data from the files
 * scramble the data, and print the data to the console.
 * You should not have to touch these.
 **********************************************************/

/*
	Function: readFromFile()
	Purpose: 
		readFromFile reads values from a file into a vector<T>. 
		It returns true if the file was successfully opened and 
		read, and false otherwise.
*/
template <typename T>
bool readFromFile(vector<T>& v, string filename)
{
    ifstream file;
    T tmp;
	
    file.open(filename);
	if(file.is_open())
	{
		//place file contents into vector
		while(file >> tmp)
		{
			v.push_back(tmp);
		}
		file.close();
		return true;
	}
	return false;
}

/*
	Function: printVector()
	Purpose: 
		printVector prints each element of the vector to the screen
*/
template <typename T>
void printVector(vector<T>& v)
{
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << endl;
    }
}

/*
	Function: scramble()
	Purpose: 
		scramble will randomly scramble the vector contents to
		make the vector unsorted
*/
template <typename T>
void scramble(vector<T>& v)
{
    srand(time(0));
    int randomIndex;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        randomIndex = rand() % v.size();
        swap(v[i], v[randomIndex]);
    }
}

/*************************************************
 * SORTING FUNCTIONS
 * These functions implement the sorting algorithms
 *************************************************/

// Implement all the sort algorithms below that were described in the assignment
