/*
	Title:  vector3.cpp
	Author:  April Crockett
	Date:  10/10/2017
	Purpose:  To demonstrate parallel vectors
*/

#include <iostream>
#include <vector> //must be included to create & use a vector
using namespace std;

int main()
{
	const int SIZE = 3;
	vector<int> numPiecesCandy(SIZE);
	vector<string> childNames(SIZE); 
	
	cout << "\n\nHow many pieces of candy did you eat on Halloween night?\n";
	for(int x = 0; x < SIZE; x++)
	{
		cout << "\nNAME?  ";
		getline(cin, childNames.at(x));
		
		cout << "PIECES CANDY:  ";
		cin >> numPiecesCandy.at(x);
		cin.ignore();
	}
	
	//find the max
	int max = numPiecesCandy.at(0);
	string child = childNames.at(0);
	for(int x = 1; x < SIZE; x++)
	{
		if(numPiecesCandy.at(x) > max) //if true then we have a new max
		{
			max = numPiecesCandy.at(x);
			child = childNames.at(x);
		}
	}
	
	cout << "\n\n" << child << " ate " << max << " pieces of candy!!!";
	
	//find the average
	int total = 0;
	float avg;
	for(int x = 0; x < SIZE; x++)
	{
		total += numPiecesCandy.at(x);
	}	
	avg = total / static_cast<float>(SIZE);
	
	cout << "\n\nThe average number of pieces of candy eaten by the children is ";
	cout << avg << endl << endl;

	
	return 0;
}