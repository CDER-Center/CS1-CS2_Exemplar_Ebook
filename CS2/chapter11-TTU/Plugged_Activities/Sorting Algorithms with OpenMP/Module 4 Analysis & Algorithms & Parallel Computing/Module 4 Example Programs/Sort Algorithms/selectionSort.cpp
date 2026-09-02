/*
	Filename: selectionSort.cpp
	Author: April Crockett
	Last Updated: 6/3/2025
	Purpose: to demonstrate the selection sort algorithm
	
	GeeksForGeeks website: https://www.geeksforgeeks.org/selection-sort-algorithm-2/
*/
#include <iostream>
using namespace std;

void displayArray(int*, int);
void selectionSort(int*, int);

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
	int temp;  //temporary variable for swap
	cout << "\nSorting the array with the Selection Sort algorithm.\n\n";
	
	for(int i=0; i<size-1; i++){
		minIndex = i;
		minValue = arr[i];
		//find the minimum value in the array iing from i and going through the end of the array
		for(int j=i+1; j<size; j++) {
			if(arr[j] < minValue) {
				minValue = arr[j];
				minIndex = j;
			}
		}
		//now we have the index of the smallest value so swap
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
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