/*
	Filename: insertionSort.cpp
	Author: April Crockett
	Last Updated: 6/3/2025
	Purpose: to demonstrate the insertion sort algorithm
	
	GeeksForGeeks website: https://www.geeksforgeeks.org/insertion-sort-algorithm/
*/
#include <iostream>
using namespace std;

void displayArray(int*, int);
void insertionSort(int*, int);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	displayArray(myArr, 5);
	insertionSort(myArr, 5);
	displayArray(myArr, 5);
	
	return 0;
}

void insertionSort(int *arr, int size)
{
	int key; //key is the item that we are sorting at the moment
	int j;  //j is the position of where key should be inserted into the sorted array
	
	cout << "\nSorting the array with the Insertion Sort algorithm.\n\n";
	
	//i will hold the subscript of the unsorted array
	for(int i=1; i < size; i++)
	{
		key = arr[i]; // select the item to be sorted
		j = i-1; // j is the element to the furthest right of the sorted array
		// while we haven't gone out of bounds to the left of the array AND 
		// the current element is still greater than key
		while(j >= 0 && arr[j] > key) 
		{
			//move elements to the right of the sorted array 
			//that are greater than the item (key)
			arr[j+1] = arr[j]; 
			j = j-1; 
		}
		arr[j+1] = key; //place item in final sorted position
	}
}


void displayArray(int *arr, int size)
{
	cout << "\n--------------------The array:  ";
	for(int i=0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "--------------------\n";
}