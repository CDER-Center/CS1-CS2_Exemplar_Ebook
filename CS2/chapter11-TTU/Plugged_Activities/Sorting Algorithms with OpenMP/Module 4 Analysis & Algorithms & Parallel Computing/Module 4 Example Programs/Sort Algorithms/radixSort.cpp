// C++ implementation of Radix Sort
#include<iostream>
using namespace std;
int getMax(int[], int);
void countSort(int[], int, int);
void radixsort(int[], int);
void print(int[], int);

int main(){
    int arr[] = {170, 45, 75, 90, 02, 802, 2, 66};
    int arraySize = sizeof(arr)/sizeof(arr[0]);
	cout << endl << endl;
	print(arr, arraySize);
    radixsort(arr, arraySize);
    print(arr, arraySize);
    return 0;
}
// The main function that sorts arr[] of size arraySize using Radix Sort
void radixsort(int arr[], int arraySize){
    // Find the maximum number to know number of digits
    int maxNum = getMax(arr, arraySize);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; maxNum/exp > 0; exp *= 10)
        countSort(arr, arraySize, exp);
}
// get maximum value in arr[]
int getMax(int arr[], int arraySize){
    int mx = arr[0];
    for (int i = 1; i < arraySize; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int arraySize, int exp){
    int output[arraySize]; // output array
    int i, count[10] = {0};
	/*  The count array stores how many times each digit (0 through 9) occurs 
	      for the array element in the exp place
		exp place is 1's place, 10's place, 100's place, 1000's place and so on....
	*/
    // Store count of occurrences in count[]
    for (i = 0; i < arraySize; i++)
        count[ (arr[i]/exp)%10 ]++;
    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Build the output array
    for (i = arraySize - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < arraySize; i++)
        arr[i] = output[i];
}
 
// A utility function to print an array
void print(int arr[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << arr[i] << " ";
	cout << endl << endl;
}


