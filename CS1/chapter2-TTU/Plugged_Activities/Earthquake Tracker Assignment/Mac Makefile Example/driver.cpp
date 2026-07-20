/*********************************************************************************
	Title:  	driver.cpp
	Author:  	April Crockett
	Date:		June 17, 2025
	
	Purpose:  	The main function is in this file.
	
				Concept: The program simulates a group of sea turtle hatchlings 
				trying to reach the ocean. The program does the following:
					-Gets the number of hatchlings.
					-Simulates each one's progress.
					-Calculates survival chances based on environmental conditions.

				It uses:
					-Loops to simulate each hatchling's journey.
					-Branching to handle different environmental conditions.
					-Calculations to estimate survival rates.
					
				For more information on header files, GeeksforGeeks
				has a good article:
				https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*********************************************************************************/

//we must include the header file here and since it is a file on our
//local computer, we use double quotes to enclose the filename instead of < >

#include "turtle.h"

int main()
{
	srand(time(0)); // Seed for randomness
    int numTurtles;
	int reachedOcean;
	double survivalRate;

    cout << "\n\n~~~~~ Sea Turtle Hatchling Tracker ~~~~~" << endl;
    cout << "Enter the number of sea turtle hatchlings: ";
    cin >> numTurtles;

    reachedOcean = simulateHatchlings(numTurtles);
    survivalRate = estimateSurvival(reachedOcean, numTurtles);

    cout << "\n\n~~~~~ Results ~~~~~\n";
    cout << reachedOcean << " out of " << numTurtles 
		 << " hatchlings reached the ocean." << endl;
    cout << "Estimated survival rate: " << survivalRate * 100 << "%\n";

    if (survivalRate < 0.3)
        cout << "Many hatchlings didn't survive. Consider conservation efforts!\n";
	else 
        cout << "Good survival rate! Conditions seem favorable.\n";

    return 0;
}