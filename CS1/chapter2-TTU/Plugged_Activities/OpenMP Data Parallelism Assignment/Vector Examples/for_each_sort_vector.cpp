/*
	Title:  for_each_vector.cpp
	Author: 
	Description: Using the <algorithm> library for_each loop with a vector
	
	The for_each loop will apply a function to each element of the vector.
	The function can be a lambda function or a programmer-defined function.
	
	https://cplusplus.com/reference/vector/vector/
	https://cplusplus.com/reference/algorithm/for_each/
	https://cplusplus.com/reference/algorithm/sort/

*/
#include <vector>
#include <algorithm> //to use for_each() and sort()
#include <iostream>

using namespace std;

void printWord(string);

int main() 
{
	vector<string> words = {"Dog","Cat","Horse","Cow","Chicken","Rat","Pig","Iguana","Spider"};
	int count;
	
	//for each with lambda function that prepends the number of characters to each word in words
	cout << endl << "Prepending the count of the number of characters in each word using a for_each loop in the <algorithm> library and a lambda function.\n";
    for_each(words.begin(), words.end(), [](string &word) { 
		int count = 0;
		for(int i=0;i<word.length();i++)
			count++;
		word=to_string(count)+"_"+word;		
	});
	
	//sort the words in the vector using the <algorithm> library's sort function
	sort(words.begin(), words.end());
	
	//for each loop calling a function that prints the word
	cout << "\nNow printing the words using a for_each loop in the <algorithm> library and a programmer-defined function.\n";
	for_each(words.begin(), words.end(), printWord);
	
	
	cout << endl << endl;
	
	return 0;
}

void printWord(string str)
{
	cout << str << endl;
}
