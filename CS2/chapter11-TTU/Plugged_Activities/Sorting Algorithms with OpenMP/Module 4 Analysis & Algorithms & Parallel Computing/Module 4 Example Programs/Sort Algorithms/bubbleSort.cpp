/*
	Filename: bubbleSort.cpp (the inefficient, traditional version)
	Author: April Crockett
	Last Updated: 6/3/2025
	Purpose: to demonstrate the basic bubble sort algorithm.
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
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-i-1; j++) {
			//swap the two adjacent elements if the one on the left is greater than the one on the right
			if(arr[j] > arr[j+1]) {
				tempForSwap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tempForSwap;
			}
		}
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