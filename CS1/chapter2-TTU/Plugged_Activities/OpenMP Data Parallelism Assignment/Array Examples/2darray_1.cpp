/*
	Title:  2darray_1.cpp
	Author:  April Crockett
	Date:  8/2/2017
	Purpose:  This program demonstrates a two-dimensional array.
*/
#include <iostream>
using namespace std;

int main()
{
	//THE EXTRA BRACES AROUND EACH ROW'S INITIALIZATION LIST ARE OPTIONAL
	//BUT GOOD PROGRAMMING PRACTICE.
	//EXTRA BRACES ALSO ALLOW YOU TO PARTIALLY INITIALIZE A ROW
	int table[3][2] = 	{	{1},
							{3, 4},
							{5}
						};
	float rainfall[3][2] = 	{	{4.5, 2.4},
								{5.2, 1.2},
								{7.8, 1.4}
							};
	float total=0.0;					
	
	cout << endl << endl;
	
	//print out the rainfall array
	for(int row=0; row < 3; row++)	
	{
		for(int col=0; col < 2; col++)
		{
			cout << rainfall[row][col] << " ";
		}
		cout << endl;
	}	

	//accumulate the total rainfall by adding up all array elements in the 2d array
	for(int row=0; row < 3; row++)	
	{
		for(int col=0; col < 2; col++)
		{
			total += rainfall[row][col];
		}
	}
	
	cout << "\n\nThe total rainfall is " << total << endl << endl;
										
	return 0;
}
