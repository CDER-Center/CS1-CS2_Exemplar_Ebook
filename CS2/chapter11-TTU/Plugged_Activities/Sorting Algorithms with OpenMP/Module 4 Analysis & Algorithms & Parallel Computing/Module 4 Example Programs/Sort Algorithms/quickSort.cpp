#include <iostream>
using namespace std;
void displayArray(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int& one, int& two);

int main(){
	const int SIZE = 5;
	int myArr[SIZE] = {85, 42, 7, 186, 18};
	cout << endl << endl;
	displayArray(myArr, SIZE);
	cout << endl;
	quickSort(myArr, 0, SIZE-1);
	cout << endl;
	displayArray(myArr, SIZE);
	cout << endl << endl;
	return 0;
}

void quickSort(int *arr, int left, int right) {
	int split = 0;
	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (left >= right) {
		return;
	}
	/* Partition the data within the array. */
	split = partition(arr, left, right); //returns location of last element in left partition
	quickSort(arr, left, split); //recursively sort left partition
	quickSort(arr, split+1, right); //recursively sort right partition
}
int partition(int *arr, int left, int right) {
   int pivot = arr[left]; //pivot starts at left
   left--;
   right++;
   while(left < right){
	   do{
		   right--;
	   } while(arr[right] > pivot);
	   do{
		   left++;
	   }while(arr[left] < pivot);
	  
	   if(left < right)
		swap(arr[left], arr[right]);
   }
   return right;
}
void swap(int& one, int& two){
	int temp = one;
	one = two;
	two = temp;
}

void displayArray(int *arr, int size){
	cout << "\n--------------------The array:  ";
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << "--------------------\n";
}