#include <iostream>
using namespace std;

void displayArray(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int& one, int& two);

int main()
{
	const int SIZE = 5;
	int myArr[SIZE] = {85, 42, 7, 186, 18};
	
	//display the array
	cout << endl << endl;
	displayArray(myArr, SIZE);
	cout << endl;
	//sort the array
	quickSort(myArr, 0, SIZE-1);
	//display the array
	cout << endl;
	displayArray(myArr, SIZE);
	cout << endl << endl;
	
	return 0;
}

void quickSort(int *arr, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(arr, low, high); //returns location of last element in low partition
	quickSort(arr, low, pivot_location); //recursively sort low partition
	quickSort(arr, pivot_location + 1, high); //recursively sort high partition
}

//mid Partition algorithm
int partition(int *arr, int left, int right) {

   int pivot, middle, temp;
   bool done = false;
   
   //pivot starts at middle
   middle = left + (right-left) / 2;
   pivot = arr[middle];
   int l = left;
   int r = right;
   while(!done)
   {
		while(arr[l] < pivot) //increment l while arr[l] < pivot
		   ++l;
		while(pivot < arr[r])//decrement r while pivot < arr[r]
		   --r;
		
		//if there are 0 or 1 elements remaining, all numbers are partiioned.  return r
		if(l >= r)
			done = true;
		else
		{
			//swap & update l and r
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			++l;
			--r;
		}
   }
   return r;   
}

void swap(int& one, int& two)
{
	cout << "\nSwapping " << one << " & " << two;
	int temp = one;
	one = two;
	two = temp;
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