/*
	Title:  	arrayInitialize_2.cpp
	Author:  	Gaddis, modified by Crockett
	Date:  		8/2/2017
	Purpose:  	This program initializes a string array
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int SIZE = 9;
	string planets[SIZE] = { "Mercury", "Venus", "Earth", "Mars",
							 "Jupiter", "Saturn", "Uranus",
							 "Neptune", "Pluto (a dwarf planet)" }; //full initialization list
	bool boolArray[] = {true, false, true, true, false, false};
	cout << "Here are the planets:\n";

	for (int count = 0; count < SIZE; count++)
		cout << planets[count] << endl;

	return 0;
}