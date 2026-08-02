/*
	Title:  arrayExample_0.cpp
	Author: April Crockett
	Date:  7/28/2017
	Purpose:  to demonstrate an array.  This program asks 
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
	cout << "\nEmployee 1: ";
	cin >> hours[0]; 
	cout << "\nEmployee 2: ";
	cin >> hours[1];
	cout << "\nEmployee 3: ";
	cin >> hours[2];
	cout << "\nEmployee 4: ";
	cin >> hours[3];
	cout << "\nEmployee 5: ";
	cin >> hours[4];
	cout << "\nEmployee 6: ";
	cin >> hours[5];

	// Display the values in the array.
	cout << "The hours you entered are:";
	cout << hours[0] << " ";
	cout << hours[1] << " ";
	cout << hours[2] << " ";
	cout << hours[3] << " ";
	cout << hours[4] << " ";
	cout << hours[5];

	cout << endl << endl;
	cout << hours << endl << endl;

	return 0;
}




