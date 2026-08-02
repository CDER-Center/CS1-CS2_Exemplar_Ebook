/*
	Title:  charArrays_2.cpp
	Author:  April Crockett
	Date:  10/30/2024
	Purpose:  Demonstrate differences between C++ string class string,
				character array (c-string), and integer array.
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str1 = "April";
	string str2 = "NotApril";
	int intArray[6] = {2, 4, 6, 7, 3, 9};
	char cstring1[100] = "Ruth";
	char cstring2[10] = "Ruth";
	
	//HOW TO PRINT ALL THESE VARIABLES
	cout << "\n***************** PRINTING *****************\n";
	cout << "\n\nPrinting the strings & arrays:\n";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "intArray: ";
	for (int i=0; i <= 6; i++)
		cout << intArray[i] << " ";
	cout << endl;
	cout << "cstring1: " << cstring1 << endl;
	cout << "cstring2: " << cstring2 << endl;
	
	cout << "\nPrinting out the integer array with one integer per line:\n";
	for(int x=0; x<5; x++)
		cout << intArray[x] << endl;

	cout << "\nPrinting out the c-string 1 character at a time with an endline after each character:\n";
	for(int x=0; x<5; x++)
		cout << cstring1[x] << endl;
	
	//COMPARING
	cout << "***************** COMPARING *****************\n";
	//you CAN compare strings with relational operators
	cout << "Comparing C++ string class strings with relational operator:\n";
	if(str1 == str2)
		cout << "str1 (" << str1 << " & str2 ("
			 << str2 << ") C++ string class strings are the SAME!\n";
	else
		cout << "str1 (" << str1 << " & str2 ("
			 << str2 << ") C++ string class strings are not the same.\n";
	
	/*	C++ will allow you to compare c-strings with relational operators, 
		HOWEVER, this will only compare the memory addresses of the arrays!
		Therefore, it will always be false because two arrays can't occupy
		the same space.
	*/
	cout << "\nComparing c-strings with relational operator (comparing memory addresses):\n";
	if(cstring1 == cstring2)
		cout << "cstring1 (" << cstring1 << " & cstring2 ("
			 << cstring2 << " C-STRINGS are the SAME!\n";
	else
		cout << "cstring1 (" << cstring1 << " & cstring2 ("
			 << cstring2 << " C-STRINGS are not the same.\n";
			 
	//the correct way to compare c-strings is with strcmp
	//strcmp will return 0 if the two c-strings are the same
	cout << "\nNow, comparing c-strings the correct way with strcmp() function: ";
	if(strcmp(cstring1, cstring2) == 0)
		cout << "\ncstring1 (" << cstring1 << " & cstring2 ("
			 << cstring2 << " C-STRINGS are the SAME!\n";
	else
		cout << "\ncstring1 (" << cstring1 << " & cstring2 ("
			 << cstring2 << " C-STRINGS are not the same.\n";
	
	cout << "\n***************** COPYING & CONCATENATING *****************\n";
	
	//2 functions for copying c-strings (strncpy & strcpy)
	
	//strncpy
	cout << "Using strncpy to copy the number of characters specified by\n3rd argument "
	     << "of the 2nd argument (c-string) to the 1st argument (c-string).\n"
		 << "BEFORE using strncpy, cstring1 is " << cstring1 << "\n";
	strncpy(cstring1, "Ralph", 3);
	cout << "AFTER using strncpy, copying 3 characters of \"Ralph\" "
		 << " to cstring1, cstring1 is " << cstring1 << "\n\n";
	
	//strcpy
	cout << "Using strcpy to copy the 2nd argument (c-string) to the "
	     << "1st argument (c-string).\n"
		 << "BEFORE using strcpy, cstring2 is " << cstring2 << "\n";
	strcpy(cstring2, "Have a Great Day");
	cout << "AFTER using strcpy, copying \"Have a Great Day\""
		 << " to cstring2, cstring2 is " << cstring2 << "\n\n";
	/*	NOTE: cstring2 is only 10 elements, but I am trying to place 16 characters
		plus the null terminator (17 characters) into the c-string. I should get a
		warning about this whenever I compile!
	*/
		 
	//2 functions for concatenating, which means appending to the end (strncat & strcat)
	
	//strncat
	cout << "Using strncat to append (to the end) the number of "
		 << "characters specified by 3rd argument \n"
	     << "of the 2nd argument (c-string) to the 1st argument (c-string).\n"
		 << "BEFORE using strncat, cstring1 is " << cstring1 << "\n";
	strncat(cstring1, " Smith", 4);
	cout << "AFTER using strncat, copying 4 characters of \" Smith\" "
		 << " to cstring1,\n cstring1 is " << cstring1 << "\n";
	
	//strcat
	cout << "\nUsing strcat to append (to the end) the 2nd argument (c-string) to the "
	     << "1st argument (c-string).\n"
		 << "BEFORE using strcat, cstring2 is " << cstring2 << "\n";
	strcat(cstring2, ", CSC 1300 students!");
	cout << "AFTER using strcat, copying \", CSC 1300 students!\""
		 << " to cstring2,\n cstring2 is " << cstring2 << "\n";
	
	/*	NOTE: cstring2 is only 10 elements, but I am trying to append 20 characters
		to the already out-of-bounds c-string. I should get a warning about this 
		whenever I compile! To fix, make sure cstring2 is large enough to hold 
		both strings
	*/

	cout << "\n***************** LENGTH/SIZE *****************\n";
	cout << "str1 length: " << str1.length() << endl;
	cout << "str2 length: " << str2.length() << endl;
	cout << "cstring1 length: " << strlen(cstring1) << endl;
	cout << "cstring2 length: " << strlen(cstring2) << endl;
	cout << "intArray length: " << sizeof(intArray)/sizeof(int) << endl;
	
	return 0;
}







