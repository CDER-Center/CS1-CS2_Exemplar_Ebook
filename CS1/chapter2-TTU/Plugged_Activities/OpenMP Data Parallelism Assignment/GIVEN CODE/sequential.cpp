/***********************************************************************
	TO COMPILE:  	g++ sequential.cpp -std=c++20
	
	Title:  		sequential.cpp
	Author: 		April Crockett
	Description: 	A program that computes runtime to read in words 
					from a text file, prepend the number of characters
					in the word to each word, and then sort the words
					in ascending order.			
	Date Created:	March 2024
	Last Updated:	July 2024
************************************************************************/

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono> //to calculate time elapsed (date and time library)

using namespace std;

//function prototype
bool readFromFile(vector<string>&);
void bubbleSort(vector<string>&);
void printVector(vector<string>&);

int main() 
{
	vector<string> words;
	cout << setprecision(3) << fixed;
	
	if(readFromFile(words)){
		cout << endl;
		
		//Get the current timestamp to measure elapsed time later
		 auto start = chrono::high_resolution_clock::now();
		
		/*
			The following for loop will iterate through the string 
			vector and for each element it will:
				1) Find the length of the string
				2) Convert the number of characters to a string
				3) Prepend the number of characters to the front of the string.
			Example: if the string is "apricot" then the resulting string after 
			running this code would be "7_apricot" and "cat" would turn into "3_cat"
		*/
		for (unsigned int i=0; i<words.size(); i++) {
			int string_length = words[i].length();
			words[i] = to_string(string_length) + "_" + words[i];
		}
		
		//sort the vector using bubble sort algorithm
		bubbleSort(words);
		
		//Comment out the following two lines after you test to make sure your sort function is working correctly. Test only with smallest text file.
		cout << "\n\nAfter sorting:\n";
		printVector(words);
		
		//Get the ending timestamp
		auto end = chrono::high_resolution_clock::now();
		
		//Compute time elapsed
		double compute_time_s = chrono::duration<double>(end - start).count();

		cout << string(40,'*') << endl;
		cout << "Computation time for sequential = "  << compute_time_s << " seconds." << endl << endl;
	}
	return 0;
}

/*
	Function:	readFromFile()
	Purpose:	Read each word from the words.txt text file and place
				in the str vector, which was passed by reference by calling
				the Vector push_back function.  push_back adds one new element
				at the end of the vector and places the argument sent to 
				the push_back function in that new element.
*/
bool readFromFile(vector<string>& str)
{
    ifstream file;
	string filename;
    string line;
	bool success;
	
	cout << "\nEnter the name of the text file. Below are options:\n";
	cout << "\twords_374.txt\n";
	cout << "\twords_9330.txt\n";
	cout << "\twords_18660.txt\n";
	cout << "\twords_31100.txt\n";
	cout << "\twords_466493.txt\n";
	cout << "\nFILENAME:  ";
	cin >> filename;
	file.open(filename);
	
	if(file.is_open()) {
		while (getline(file, line)) {
			str.push_back(line);
		}
		success = true;
	}
	else{
		cout << "File couldn't be opened!\n";
		success = false;
	}
	return success;
}

/*
	Function: printVector()
	Purpose:  The purpose of this function is just to print all vector
	elements with a comma between each piece of data.
	
	The only reason to call this function in this program is just to 
	test if the vector was actually sorted. When you are timing the
	program running, however, you will not want to call this function.
*/
void printVector(vector<string>& v)
{
	int n = v.size();
	cout << "All vector elements:\n";
	for(int i=0; i<n; i++)
	{
		cout << v.at(i) << ", ";
	}
	cout << endl;
}

/*
	Function: bubbleSort
	Purpose:
	Sorts a vector of strings in ascending alphabetical order
	using the bubble sort algorithm.
	This is an optimized version of bubble sort.
	
	Resources:
	Learn more about bubble sort at https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
	
	52 second visualization: https://www.youtube.com/shorts/y2AghjB4Wxs
	
*/
void bubbleSort(vector<string>& v){
    bool swapped = true;
    int n = v.size();
	for(int i=0; i<n-1; i++){
        swapped = false;
		for (int j=0; j<n-i-1; j++) {
			//compare adjacent elements
			if (v[j] > v[j+1]){ 
				//left element > right element, so swap 
				string temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				swapped = true;
			}
		}
		//if no two elements were swapped by inner loop, then break	
		if(swapped == false)
			break;
	}
}

