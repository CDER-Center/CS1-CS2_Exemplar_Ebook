/***********************************************************************
	TO COMPILE:  	g++ -fopenmp parallel.cpp -std=c++20
	
	Title:  		parallel.cpp
	Author: 		PUT YOUR NAME HERE
	Description: 	A program that computes runtime to read in words 
					from a text file, prepend the number of characters
					in the word to each word, and then sort the words
					in ascending order.			
	Date Created:	June 2025
	Last Updated:	
************************************************************************/

#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono> //to calculate time elapsed (date and time library)
#include <string>
//what library needs to be included to use OpenMP?

using namespace std;

//function prototype
bool readFromFile(vector<string>&);
void parallelBubbleSort(vector<string>&);
void printVector(vector<string>&);

int main() 
{
	//create variables & setprecision
	vector<string> words;
	
	//Force setting the number of threads to use to 5
	
	//read from the file into the vector (call readFromFile function and if the file was able to be read then continue the program. (otherwise the program should quit)
	
	//Get the current timestamp (call chrono's now() function)
	
	/*
		create a traditional for loop 
		to go through each element of vector and modify it 
		exactly as done in sequential.cpp.
		However, use an OpenMP directive to parallelize	the for loop.
	*/
	
	//call the parallelBubbleSort function to sort the vector
	
	//the printVector function call can be commented out after you test to make sure your code works (sorts the strings) with the smallest text file.
	cout << "\n\nAfter sorting:\n";
	printVector(words);
	
	//Get the current timestamp (call chrono's now() function)
	//compute the elapsed time 
	
	//print resulting computation time
	
	return 0;
}

/*
	Function:	readFromFile()
	Purpose:	Read each word from the words.txt text file and place
				in the str vector, which was passed by reference by calling
				the Vector push_back function.  push_back adds one new element
				at the end of the vector and places the argument sent to 
				the push_back function in that new element.
*/
bool readFromFile(vector<string>& str)
{
    ifstream file;
	string filename;
    string line;
	bool success;
	
	cout << "\nEnter the name of the text file. Below are options:\n";
	cout << "\twords_374.txt\n";
	cout << "\twords_9330.txt\n";
	cout << "\twords_18660.txt\n";
	cout << "\twords_31100.txt\n";
	cout << "\twords_466493.txt\n";
	cout << "\nFILENAME:  ";
	cin >> filename;
	file.open(filename);
	
	if(file.is_open()) {
		while (getline(file, line)) {
			str.push_back(line);
		}
		success = true;
	}
	else{
		cout << "File couldn't be opened!\n";
		success = false;
	}
	return success;
}

/*
	Function: printVector()
	Purpose:  The purpose of this function is just to print all vector
	elements with a comma between each piece of data.
	
	The only reason to call this function in this program is just to 
	test if the vector was actually sorted. When you are timing the
	program running, however, you will not want to call this function.
*/
void printVector(vector<string>& v)
{
	int n = v.size();
	cout << "All vector elements:\n";
	for(int i=0; i<n; i++)
	{
		cout << v.at(i) << ", ";
	}
	cout << endl;
}

/*
	Function: parallelBubbleSort()
	
	NOTE: DO NOT MODIFY THIS FUNCTION!!
	
	Purpose: The parallelBubbleSort function is really called "Odd Even Transposition Sort" or "Brick Sort" which is an altered version of 
	bubble sort in order to parallelize the sorting. In this algorithm we
	alternately swap the even items with their next item for one pass,
	and then the odd items with their next time for the next pass.
	It is similar to shaker sort. This algorithm lends itself well to
	parallelisation because all of the compare-and-swap operations in
	each pass could theoretically be performed at once.
	on a vector of strings using OpenMP to accelerate the process by taking 
	advantage of multiple CPU threads.
	
	Odd-even sort: https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort#cite_note-1
	
*/
void parallelBubbleSort(vector<string>& v)
{
    int n = v.size();
	bool swapped = true;
	
	while(swapped){
        swapped = false;		
		
		//define a parallel region
		#pragma omp parallel
		{
			/* 				
				The line below #pragma omp for reduction(||:swapped)
				uses OpenMP's logical OR (||) reduction, meaning:
					-"reduction" causes each thread to get a private copy of swapped
					-Each thread works independently and updates its own private copy
					-At the end of the parallel region (end of the for loop), OpenMP combines 
					      all the private copies using the operator specified (in this case, || = logical OR)
					-If any thread sets its swapped to true, the final shared swapped becomes true

				If you changed the line below to just #pragma omp for (removing reduction(||:swapped)
				then every thread modifies the shared variable swapped directly, 
				which can cause:
					-Race conditions (multiple threads trying to write to swapped at the same time)
					-False sharing and cache coherence issues
					-Overhead from synchronizing writes to shared memory
				This slows things down and creates unpredictable behavior.

			*/
			#pragma omp for reduction(||:swapped)
			//bubble sort vector starting with first element (index 0) and update by 2
			for (int i=0; i<n-1; i+=2) {
				if (v[i] > v[i+1]) {
					string temp = v[i];
					v[i] = v[i+1];
					v[i+1] = temp;
					swapped = true;
				}
			}
			#pragma omp for reduction(||:swapped)
			//bubble sort vector starting with second element (index 1) and update by 2
			for (int i=1; i<n-1; i+=2) {
				if (v[i] > v[i+1]) {
					string temp = v[i];
					v[i] = v[i+1];
					v[i+1] = temp;
					swapped = true;
				}
			}
		}
	}
}