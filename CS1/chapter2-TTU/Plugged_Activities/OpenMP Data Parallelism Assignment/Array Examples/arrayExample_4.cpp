/*
	Title:  arrayExample_4.cpp
	Author: Gaddis, modified by Crockett
	Date:  7/28/2017
	Purpose:  to demonstrate going out of 
		bounds of an array
*/

#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 3;
	int values[SIZE];
	int count;
	
	cout << "I will store 5 numbers in a 3-element array!\n";
	for (count = 0; count < 5; count++)
		values[count] = 100;
		
	cout << "If you see this message, it means the program\n";
	cout << "has not crashed!  Here are the numbers:\n";
	for (count = 0; count < 5; count++)
		cout << values[count] << endl;
		
	return 0;
}