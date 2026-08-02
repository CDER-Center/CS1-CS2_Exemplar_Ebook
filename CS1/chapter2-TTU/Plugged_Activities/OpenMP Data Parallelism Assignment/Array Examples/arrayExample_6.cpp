/*
	Title:  arrayExample_6.cpp
	Author:  April Crockett
	Date:  7/28/2017
	Purpose: This program gets a series of test scores and
		calculates the average of the scores with the
		lowest score dropped.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int SIZE = 4;      // Array size
	double testScores[SIZE], // Array of test scores
	total = 0,        // Total of the scores, initialized to zero
	lowestScore,      // Lowest test score
	average;          // Average test score
	double highest;

	// Set up numeric output formatting.
	cout << fixed << showpoint << setprecision(1);

	// Get the test scores from the user.
	for(int index = 0; index < SIZE; index++)
	{
		cout << "Enter test score number " << (index + 1) << ": ";
		cin >> testScores[index];
	}

	// Get the total of the test scores.
	for (int count = 0; count < SIZE; count++)
		total += testScores[count]; // Add each element to total.

	// Get the lowest test score.
	lowestScore = testScores[0];// Get the first array's first element.
	for (int count = 1; count < SIZE; count++)
	{
		if (testScores[count] < lowestScore) //if value is < current lowest, then a new lowest has been found
			lowestScore = testScores[count];
	}

	// Subtract the lowest score from the total.
	total -= lowestScore;

	// Calculate the average. Divide by 3 because the lowest test score was dropped.
	average = total / (SIZE - 1);

	// Display the average.
	cout << "The average with the lowest score " << "dropped is " << average << ".\n";

	// Get the highest test score.
	highest = testScores[0];// Get the first array's first element.
	for (int count = 1; count < SIZE; count++)
	{
		if (testScores[count] > highest) //if value is more then current highest, then a new highest has been found
			highest = testScores[count];
	}

	// Display the highest.
	cout << "\nThe highest test score is " << highest << endl;

	return 0;
}