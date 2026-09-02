/*
	Filename: insertionSortExamine.cpp
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
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	insertionSort(myArr, 5);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}
void insertionSort(int *arr, int size)
{
	int key; //key is the item that we are sorting at the moment
	int j;  //j is the position of where key should be inserted into the sorted array
	int t=0;
	
	cout << "\nSorting the array with the Insertion Sort algorithm.\n\n";
	
	//i will hold the subscript of the unsorted array
	for(int i=1; i < size; i++)
	{
		cout << "\n\nTRAVERSAL NUMBER " << t+1 << "-------------------------------------------------";
		t++;
		
		key = arr[i]; //select the item to be sorted
		cout << "\nITEM TO BE SORTED: " << key << endl;
		j = i-1; //j is the element to the furthest right of the sorted array
		while(j >= 0 && arr[j] > key) //while we haven't gone out of bounds to the left of the array and the current element is still greater than key
		{
			cout << "Moving " << arr[j] << " to the right becasue it is larger than item.\n";
			arr[j+1] = arr[j]; //move elements to the right of the sorted array that are greater than the item (key)
			j = j-1; //decrement j
		}
		arr[j+1] = key; //place item in final sorted position
		cout << "Placing " << key << " at position " << j+1 << endl;
		displayArray(arr, size);
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