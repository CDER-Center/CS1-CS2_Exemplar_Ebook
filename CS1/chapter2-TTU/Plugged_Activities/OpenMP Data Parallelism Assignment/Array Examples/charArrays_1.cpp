/*
	Title:  charArrays_1.cpp
	Author:  Gaddis, modified by Crockett
	Date:  8/2/2017
	Purpose:  This program uses an array of ten characters to store the
				first ten Letters of the alphabet. The ASCII codes of the
				characters are displayed.
*/

#include <iostream>
using namespace std;

int main()
{
	const int NUM_LETTERS = 11;
	char middleInitial = 'R';

	//char letters[NUM_LETTERS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};    
	char letters[NUM_LETTERS] = "ABCDEFGHIJ";

	cout << "Character" << "\t" << "ASCII Code\n";
	cout << "---------" << "\t" << "----------\n";

	for (int count = 0; count < (NUM_LETTERS-1); count++)
	{
		cout << letters[count] << "\t\t";
		cout << static_cast<int>(letters[count]) << endl;
	}
	
	return 0;
}



