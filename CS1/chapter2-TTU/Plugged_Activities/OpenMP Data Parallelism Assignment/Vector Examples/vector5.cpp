/*
	Title:  vector5.cpp
	Author:  April Crockett
	Date:  10/10/2017
	Purpose:  To demonstrate back() and pop_back() functions
*/

#include <iostream>
#include <vector> //must be included to create & use a vector
using namespace std;

int main()
{
	vector<int> numPiecesCandy(5);
	
	
	cout << "\n\nHow many pieces of candy did you eat on Halloween night?\n";
	for(int x = 0; x < 5; x++)
	{
		cout << "PIECES CANDY FOR CHILD " << (x+1) << ":  ";
		cin >> numPiecesCandy.at(x);
	}
	
	cout << "The last element of the vector has value " << numPiecesCandy.back() << endl;
	cout << "The number of elements in the vector is " << numPiecesCandy.size() << endl << endl;
	cout << "\nNow adding one more element using the push_back function with value 77.\n";
	numPiecesCandy.push_back(77);
	cout << "The new last element of the vector has value " << numPiecesCandy.back() << endl;
	cout << "The number of elements in the vector is " << numPiecesCandy.size() << endl << endl;
	cout << "Now use pop_back to remove the last element\n";
	numPiecesCandy.pop_back(); //removes last element
	cout << "The new last element of the vector has value " << numPiecesCandy.back() << endl;
	cout << "The number of elements in the vector is " << numPiecesCandy.size() << endl;
	
	cout << endl;
	
	return 0;
}