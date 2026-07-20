/*
	Title:  	arrayExample_1.cpp
	Author: 	Gaddis, modified by Crockett
	Date:  		7/28/2017
	Purpose:  	to demonstrate an array.  This program asks 
				for the number of hours worked by six employees. 
				It stores the values in an array.
*/
#include <iostream>
using namespace std;

int main()
{
	const int NUM_EMPLOYEES = 6;
	int hours[NUM_EMPLOYEES];

	// Get the hours worked by each employee.
	cout << "\n\nEnter the hours worked by " << NUM_EMPLOYEES << " employees: ";
	for(int i=0; i < NUM_EMPLOYEES; i++)
	{
		cout << "\nEmployee " << (i+1) << ":  ";
		cin >> hours[i]; 
	}

	// Display the values in the array.
	cout << "The hours you entered are:";
	for(int i=0; i < NUM_EMPLOYEES; i++)
		cout << hours[i] << " ";
	
	cout << endl << endl;

	return 0;
}