/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		GIVEN: program2.h
	Author: 		Eddie Gannod & April Crockett & PUT YOUR NAME HERE
	Last Updated:	PUT TODAYS DATE HERE
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#ifndef PROGRAM2_H
#define PROGRAM2_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
bool readFromFile(vector<T>&, string);
template <typename T>
void printVector(vector<T>&);
template <typename T>
void scramble(vector<T>&);

/********************************************************
 * Declare the function prototypes below for each sort
 * function 
 ********************************************************/


#endif