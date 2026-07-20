/*
	Title:  vector4.cpp
	Author:  April Crockett
	Date:  10/10/2017
	Purpose:  To demonstrate resize & size
*/

#include <iostream>
#include <vector> //must be included to create & use a vector
using namespace std;

int main()
{
	int numChildren;
	vector<int> numPiecesCandy;
	vector<string> childNames; 
	
	cout << "\n\nHow many children ate halloween candy?\n";
	cin >> numChildren;
	cin.ignore();
	
	numPiecesCandy.resize(numChildren);
	childNames.resize(numChildren);
	
	
	
	cout << "\n\nHow many pieces of candy did you eat on Halloween night?\n";
	for(int x = 0; x < numPiecesCandy.size(); x++)
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
	for(int x = 1; x < numPiecesCandy.size(); x++)
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
	for(int x = 0; x < numPiecesCandy.size(); x++)
	{
		total += numPiecesCandy.at(x);
	}	
	avg = total / static_cast<float>(numPiecesCandy.size());
	
	cout << "\n\nThe average number of pieces of candy eaten by the children is ";
	cout << avg << endl << endl;

	
	return 0;
}