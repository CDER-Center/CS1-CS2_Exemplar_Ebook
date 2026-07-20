/*
	Title:  vector6.cpp
	Author:  April Crockett
	Date:  10/10/2017
	Purpose:  To demonstrate going out of bounds of vector
*/

#include <iostream>
#include <vector> //must be included to create & use a vector
using namespace std;

void printGroceryStaples(vector<string>);
void changeOneElement(vector<string>); //pass by value
void changeAnotherElement(vector<string>&); //pass by reference

int main()
{
	//create a vector with 3 elements of data type string
	vector<string> groceryStaples(3);
	
	//an integer literal can be used to represent the index of each element
	
	groceryStaples.at(0) = "Milk"; 
	groceryStaples.at(1) = "Eggs"; 
	groceryStaples.at(2) = "Peanut Butter";
	groceryStaples.at(14) = "Jalapeño Peppers";

	printGroceryStaples(groceryStaples);
	changeOneElement(groceryStaples);
	printGroceryStaples(groceryStaples);
	changeAnotherElement(groceryStaples);
	printGroceryStaples(groceryStaples);
	
	
	return 0;
}

void printGroceryStaples(vector<string> gS)
{
	for(int x=0; x < gS.size(); x++) 
	{
		cout << gS.at(x) << endl;
	}
}

void changeOneElement(vector<string> gS)
{
	gS.at(0) = "Garlic Salt";
}

void changeAnotherElement(vector<string>& gS)
{
	gS.at(0) = "Pepper";
}