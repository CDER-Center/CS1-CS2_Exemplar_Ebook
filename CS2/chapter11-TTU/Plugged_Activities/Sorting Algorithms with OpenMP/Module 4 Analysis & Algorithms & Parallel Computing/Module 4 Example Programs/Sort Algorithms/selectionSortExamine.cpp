/*
	Filename: selectionSortExamine.cpp
	Author: April Crockett
	Last Updated: 6/3/2025
	Purpose: to demonstrate the selection sort algorithm
	
	GeeksForGeeks website: https://www.geeksforgeeks.org/selection-sort-algorithm-2/
*/
#include <iostream>
using namespace std;

void displayArray(int*, int);
void selectionSort(int*, int);
void swap(int*, int*);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	selectionSort(myArr, 5);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}

void selectionSort(int *arr, int size)
{
	int minIndex, minValue;
	cout << "\nSorting the array with the Selection Sort algorithm.\n\n";
	
	for(int i=0; i<size-1; i++)
	{
		cout << "\n\nTRAVERSAL NUMBER " << i+1 << "-------------------------------------------------\n";
		minIndex = i;
		minValue = arr[i];
		
		//find the minimum value in the array iing from i and going through the end of the array
		for(int j=i+1; j<size; j++) //using i for "index"
		{
			cout << "Comparing the current minimum (" << minValue << ") with  element at index " << j << " with value " << arr[j] << endl;
			if(arr[j] < minValue) 
			{
				minValue = arr[j];
				minIndex = j;
			}
		}
		cout << "\nThe minimum is " << minValue << " at index " << minIndex;
		cout << "\nSwapping " << arr[minIndex] << " and " << arr[i];
		//now we have the index of the smallest value so swap
		swap(arr[minIndex], arr[i]);
		displayArray(arr, 5);
	}
}

//swap a & b in memory
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
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