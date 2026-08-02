/*
	Title:  vector1.cpp
	Author:  April Crockett
	Date:  10/10/2017
	Purpose:  To demonstrate creating and using a vector1
*/

#include <iostream>
#include <vector> //must be included to create & use a vector
using namespace std;

int main()
{
	//create a vector with 100 elements of data type string
	vector<string> groceryStaples(100);
	
	//an integer literal can be used to represent the index of each element
	
	groceryStaples.at(0) = "Milk"; //index zero, first element of vector
	groceryStaples.at(1) = "Eggs"; //index one, second element of vector
	groceryStaples.at(2) = "Peanut Butter";
	
	//you can use a variable for the index instead of an integer literal
	
	for(int x=0; x<3; x++) //print three elements of the groceryStaples vector
	{
		cout << groceryStaples.at(x) << endl;
	}
	
	return 0;
}