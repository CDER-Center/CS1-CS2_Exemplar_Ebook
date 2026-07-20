/*	
	Filename: chrono.cpp
	Author: April Crockett
	Date: 10/24/2025
	Purpose: To demonstrate using the chrono class
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	
    double duration;
    vector<int> data; 
	int size;
	char response;
	srand(time(0)); //seed random generator
	
	do{
		cout << "\nWhat size do you want your vector to be? ";
		cin >> size;
		data.resize(size);
		
		//get a starting timestamp
		auto start = chrono::high_resolution_clock::now();
		
		cout << "Just started the timer!\n";
		
		for (unsigned int i = 0; i < data.size(); i++) {
				data.at(i) = rand(); 
				cout << data.at(i) << ", ";
		}
		cout << endl << "Finished. Now stop the timer!\n";
		auto end = chrono::high_resolution_clock::now();
		
		duration = chrono::duration<double>(end - start).count(); 
		cout << "SECONDS: " << duration << endl << endl;
		
		cout << "Do you want to run again? (y/n)  ";
		cin >> response;
		
	} while(response != 'n');
	

    return 0;
}
