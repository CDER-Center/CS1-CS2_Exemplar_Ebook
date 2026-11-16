/*	
	Filename: quickSort.h
	Author: April Crockett
	Date: 7/4/2025
	
*/		 
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

using namespace std;

void readFromFile(vector<string>&, string);
void printVector(vector<string>&);
void scramble(vector<string>&);
int partition(vector<string>&, int, int); //needed for quicksort
void serialQuickSort(vector<string>&, int, int);

#endif