/*
	Title:  foreach_vector.cpp
	Author: 
	Description: Using a foreach loop with a vector
	
	ABOUT:  foreach loop iterates over the elements of arrays, vectors, or any other data sets. It assigns the value of the current element to the variable iterator declared inside the loop.
	
	for(type variable_name : array/vector_name)
	{
		loop statements
		...
	}
	
	COMPILE:  g++ foreach_vector.cpp -std=c++11
	
	The foreach loop  is compatible only with C++ version 11 and greater

*/
#include <vector>
#include <iostream>

using namespace std;

int main() 
{
	vector<string> words = {"Dog","Cat","Horse","Cow","Chicken","Rat","Pig","Iguana","Spider"};
	int count;

	cout << endl << "Printing the words in the vector after prepending the count of the number of characters to each word using a foreach loop.\n";
	for(string word : words)
	{
		count = 0;
		for(int i = 0; i < word.length(); i++)
			count++;
		word = to_string(count) + "_" + word;
		cout << word << endl;
	}
	
	cout << endl << endl;
	
	//print using range-based foreach loop - notice the words do not still have the count
	// of the number of characters prepending the word
	cout << "Now printing the words again using another foreach loop.\n";
	for(string str : words)
		cout << str << endl;
	
	return 0;
}

/*
	Advantages and Disadvantages of the foreach loop in C++
	
	1. Advantages of foreach loop
			-Makes the code more readable.			
			-Easy to implement
			-Does not require pre-initialization of the iterator
			-Works with vectors and C++ built-in arrays
	
	2. Disadvantages of foreach loop
			-Cannot directly access the corresponding element indices
			-Cannot traverse the elements in reverse order
			-It doesn’t allow the user to skip any element as it traverses over each one of them

	Conclusion

		The foreach loop in C++ has its own pros and cons. The code is easy to read but it restricts some of the actions that the normal for loop offers. Hence, it completely depends on the user what he/she wants the loop to perform and choose accordingly.
		
*/