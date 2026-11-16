// This program demonstrates the binarySearch function, which
// performs a binary search on an integer array.

#include <iostream>
using namespace std;

// Function prototype
int binarySearch(const int [], int, int);
const int SIZE = 20;

int main(){
	// Array with employee IDs sorted in ascending order.
	int idNums[SIZE] = {101, 142, 147, 189, 199, 207, 222,
						234, 289, 296, 310, 319, 388, 394,
						417, 429, 447, 521, 536, 600};
	int position;   // To hold the index position of the ID in the array
	int empID;     // To hold an employee ID

	// Get an employee ID to search for.
	cout << "Enter the employee ID you wish to search for: ";
	cin >> empID;

	// Search for the ID.
	position = binarySearch(idNums, SIZE, empID);

	// If position contains -1 the ID was not found.
	if (position == -1)
		cout << "That number does not exist in the array.\n";
	else
	{
		// Otherwise position contains the subscript of the specified employee ID in the array.
		cout << "That ID is found at element " << position + 1;
		cout << " in the array.\n";
	}
	return 0;
}

/*
	Function: binarySearch()
	Purpose: To perform a binary search algorithm on an array, which is passed to the function
			 along with the size of the array and the value to be searched for.
			 The function returns the index of the element if found, otherwise it returns -1.
*/
int binarySearch(const int array[], int size, int value)
{
	int first = 0,         // First array element - index of first element
	last = size - 1,       // Last array element - index of last element
	middle,                // Mid point of search - index of middle element
	position = -1;         // Position of search value
	bool found = false;    // Flag when value is found

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (array[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}
	return position;
}


