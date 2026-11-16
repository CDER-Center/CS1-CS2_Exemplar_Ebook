/*	
   derrived from work by April Crocket at Tennessee Tech
*/

#include <iostream>
#include <vector>			  // used to create and use vectors
#include <fstream>			  // used to read in from movies.txt
#include <cstdlib>            // used for random number generation
#include "quicksort.h" 


using namespace std;

int main() 
{
	//create a vector to hold the movie titles
    vector<string> movies;
	
   
    readFromFile(movies, "movies.txt");
   
	//************************************ SERIAL QUICK SORT
	
	//make sure the movies vector is NOT sorted first to get 
	//accurate runtime of algorithm with unsorted vector
    scramble(movies); 

    serialQuickSort(movies, 0, movies.size() - 1);
	printVector(movies); 
    
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
