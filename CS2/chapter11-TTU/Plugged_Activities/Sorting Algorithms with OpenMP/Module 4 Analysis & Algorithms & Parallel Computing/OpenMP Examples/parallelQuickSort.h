/*	
	Filename: parallelQuickSort.h
	Author: April Crockett
	Date: 7/4/2025
	Purpose: To demonstrate using OpenMP to parallelize the quick sort algorithm.
*/		 
#ifndef PARALLELQUICKSORT_H
#define PARALLELQUICKSORT_H

#include <vector>
#include <string>

using namespace std;

void readFromFile(vector<string>&, string);
void printVector(vector<string>&);
void scramble(vector<string>&);
int partition(vector<string>&, int, int); //needed for quicksort
void parallelQuickSort(vector<string>&, int, int, int);
void serialQuickSort(vector<string>&, int, int);

#endif