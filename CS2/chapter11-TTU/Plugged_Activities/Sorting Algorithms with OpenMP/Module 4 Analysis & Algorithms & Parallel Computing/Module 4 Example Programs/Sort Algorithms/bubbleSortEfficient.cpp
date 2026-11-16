/*
	Filename: bubbleSort.cpp
	Author: April Crockett
	Last Updated: 6/3/2025
	Purpose: to demonstrate the bubble sort algorithm.
	
	Note: this is an optimized version of bubble sort.
	
	GeeksforGeeks website: https://www.geeksforgeeks.org/bubble-sort-algorithm/
*/
#include <iostream>
using namespace std;

void displayArray(int*, int);
void bubbleSort(int*, int);

int main(){
	int myArr[5] = {85, 42, 7, 186, 18};
	
	displayArray(myArr, 5);
	bubbleSort(myArr, 5);
	displayArray(myArr, 5);
	
	return 0;
}

void bubbleSort(int *arr, int size){
	int tempForSwap;
	bool swapped; //to keep track of whether a swap occurred in the inner loop
	
	for(int i=0; i<size-1; i++){
		swapped = false;
		for(int j=0; j<size-i-1; j++){ 
			//swap the two adjacent elements if the one on the 
			//left is greater than the one on the right
			if(arr[j] > arr[j+1]) {
				tempForSwap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tempForSwap;
				swapped = true; //a swap occurred
			}
		}
		//if there were no swaps, then break
		if(!swapped)
			break; //prevents unnecessary passes through the array
	}
}

void displayArray(int *arr, int size){
	cout << "\n--------------------The array:  ";
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "--------------------\n";
}