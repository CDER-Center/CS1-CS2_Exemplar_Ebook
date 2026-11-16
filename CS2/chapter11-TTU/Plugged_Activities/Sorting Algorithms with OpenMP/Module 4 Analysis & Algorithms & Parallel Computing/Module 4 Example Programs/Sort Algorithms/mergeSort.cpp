/*
	Filename: mergeSort.cpp
	Author: April Crockett
	Last Udated: 6/3/2025
	Purpose: to demonstrate the merge sort algorithm
*/

#include <iostream>
using namespace std;

void displayArray(int*, int);
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	MergeSort(myArr, 0, 4);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}

void MergeSort(int arr[], int beg, int end) {
   int mid = 0;
   
   if (beg < end)  //recursive case (when beg == end then that is base case) 
   {
		mid = (beg + end) / 2;  // Find the midpoint in the partition

		MergeSort(arr, beg, mid); //recursively sort left partition
		MergeSort(arr, mid + 1, end); //recursively sort right partition

		// Merge left and right partition in sorted order
		Merge(arr, beg, mid, end);
   }
}

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // size of left half
    int n2 = right - mid;     // size of right half

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data into temp arrays
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the two temp arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements, if any
    while (i < n1) 
		arr[k++] = L[i++];
    while (j < n2) 
		arr[k++] = R[j++];

    // Free temporary memory
    delete[] L;
    delete[] R;
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