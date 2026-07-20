/*
	Title:  	arrayInitialize_1.cpp
	Author:  	Gaddis, modified by Crockett
	Date:  		8/2/2017
	Purpose:  	This program displays the number of days in each month.
*/
#include <iostream>
using namespace std;

int main()
{
	const int MONTHS = 12;
	int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //full initialization list
	double quarterlySales[4] = {39485.34,498593.35,3948.3,3999543.3};
	
	for (int count = 0; count < MONTHS; count++)
		cout << "Month " << (count + 1) << " has " << days[count] << " days.\n";
	
	return 0;
}