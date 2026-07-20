/*
	Title:  foreach_1.cpp
	Author: April Crockett
	Date:  7/2/2024
	Purpose:  to demonstrate a foreach loop using auto
*/

#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 3;
	int values[SIZE];
	
	cout << "\nI will store 100 in every element of the array!\n\n";
	/*
		notice that when doing assignment in the foreach loop, you have to use 
		a reference to the element by adding & after auto.
	*/
	for (auto& value : values)
		value = 100;

		
	cout << "Now I am printing out the elements in the array:\n";
	/*
		a reference to the element doesn't have to be used when just printing
		out array contents
	*/
	for (auto value : values)
		cout << value << endl;
		
	return 0;
}