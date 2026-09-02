// This program demonstrates the linear search algorithm.
#include <iostream>
using namespace std;

int linearSearch(const int[], int, int);

int main(){
   const int SIZE = 5;
   int tests[SIZE] = { 87, 75, 98, 100, 82 };
   int position, key;

   cout << "\n\nWhat number are you searching for? ";
   cin >> key;

   // Search the array for key.
   position = linearSearch(tests, SIZE, key);

   if (position == -1) //key wasn't found if position is -1
      cout << "You did not find " << key << " in the array.\n";
   else
      cout << "You found " << key << " at index " << position << "!\n\n";

   return 0;
}

/*
   Function: linearSearch()
   Purpose: implements the linear search algorithm to search for a key
            (value) in the given array
*/
int linearSearch(const int arr[], int size, int value){
   int index = 0;       // begin at index 0 for the search
   int position = -1;   // To record position of search value
   bool found = false;  // Flag to indicate if the value was found

   while (index < size && !found){
      if (arr[index] == value) {
         found = true;         // Set the flag
         position = index;     // Record the value's subscript
      }
      index++;                 // Go to the next element
   }
   return position;            // Return the position, or -1
}