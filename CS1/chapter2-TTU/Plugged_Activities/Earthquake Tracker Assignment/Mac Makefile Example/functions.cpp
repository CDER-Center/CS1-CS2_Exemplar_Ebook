/*********************************************************************************
	Title:  	functions.cpp
	Author:  	April Crockett
	Date:		June 17, 2025
	Purpose:  	All programmer-defined functions are defined in this file.
	
*********************************************************************************/

//we must include the header file here and since it is a file on our
//local computer, we use double quotes to enclose the filename instead of < >

#include "turtle.h"

/*
	Function: 	simulateHatchlings()
	Purpose: 	Simulate the journey of hatchlings to the ocean
*/
int simulateHatchlings(int numTurtles) 
{
    int count = 0;
	int distance;
	int temperature;
	bool predatorNearby;

    for (int i = 1; i <= numTurtles; i++) 
	{
        distance = rand() % 50 + 10; // Distance in meters
        temperature = rand() % 15 + 20; // Temperature in °C (20-35)
        predatorNearby = rand() % 2; // 0 or 1

        cout << "\nHatchling " << i << " - ";
        cout << "Distance: " << distance << " meters, ";
        cout << "Temperature: " << temperature << " Celsius, ";
		if(predatorNearby)
			cout << "Predator nearby!";
		else
			cout << "No predator nearby.";

        if (distance < 30 && temperature >= 25 && !predatorNearby) 
		{
            cout << " => Reached ocean!";
            count++;
        } 
		else 
            cout << " => Didn't make it.";
    }

    return count;
}

/*
	Function: 	estimateSurvival()
	Purpose: 	Estimate survival rate of turtle
*/
double estimateSurvival(int successful, int total) 
{
    if (total == 0) 
		return 0.0;
    return 
		static_cast<double>(successful) / total;
}

