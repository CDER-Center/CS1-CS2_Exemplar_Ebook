/******************************************************************************
	TO COMPILE:	Look at the Makefile (for your operating system)
             	as well as the assignment document

	Title:			Prog3_given.cpp (rename to Prog3.cpp)
	Author: 		(put your name)
	Date Created: 	(date started on assignment)
	Last Updated: 	
	Purpose: 		To demonstrate that data can be distributed on remote 
					computers to be accessed and manipulated from a C++ program.

*******************************************************************************/

#include <iostream>
#include <string>
// TO DO: add the other #includes that you need for this program



using json = nlohmann::json;
using namespace std;

//Function prototypes (do not change these)
static size_t WriteCallback(void*, size_t , size_t, ostream*);
string downloadDataFromURL(const string& url);

int main() 
{
	string jsonString;

	// TO DO: set the url in the line below to the URL of the page with the JSON data you are retrieving
	jsonString = downloadDataFromURL("https://put.your.url/here");
	cout << endl;
	
	// try-catch is C++ exception handling needed for this program.
    // The try statement allows you to define a block of code to be tested for errors while it is being executed.
    try 
	{
        // First, we are creating and initializing the json object by calling 
        // the parse function, which takes the JSON string 
        // and converts it into a JSON object that we can work with in C++.
        json jsonObject = json::parse(jsonString);
		
        cout << "Earthquakes with magnitude greater than or equal to 4.5: " << endl;
        int numGreater = 1;
        
        // Next, we are accessing the "features" array from the JSON object, 
        // which contains information about each earthquake.
       json features = jsonObject["features"];

        // Next, we are iterating through each element in the "features" array using a for loop.
        for (unsigned int i = 0; i < features.size(); ++i)
        {
            // Inside the loop, we are accessing each earthquake's data 
            //(element) by indexing into the "features" array.
            json element = features[i];

            // We need to checkif this particular earthquake at features[i] has a magnitude greater than 4.5
            // In each features element, there is a "properties" dictionary that contains 
            // the "mag" key for magnitude and "place" key for location
            // Note that the "properties" dictionary has many other keys, but right now we 
            // are only interested in "mag" and "place" for this part of the program
            if (// TO DO: copy/paste code from the programming assignment document) 
			{
                cout << "Earthquake " << numGreater 
                     << ": \n\tPlace: " << element["properties"]["place"] 
                     << "\n\tMagnitude: " << element["properties"]["mag"]<< endl;
                cout << endl;
                numGreater++;
            }
            // There are a lot of earthquakes so I limit it to print the first 10
            if (numGreater > 10)
                break;
		}

        /*
            TO DO: YOUR FOR LOOP GOES HERE
            Purpose: using the format given above, make a loop that will print ALL
                the earthquakes that caused a tsunami
        */

    } 
    // The catch statement allows you to define a block of code to be executed if an error occurs in the try block.
	catch (exception& e) 
    {
        // This is just going to print the exception (error) to the screen if there is one. 
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


/*******************************************************************************
	Function: 	WriteCallback()
	Purpose:  	This function defines a callback function, which is used with the 
				libcurl library to perform HTTP requests to download JSON files 
				(can also be used with HTML pages, etc).
				
				It writes downloaded data into a C++ ostream (like ofstream or cout).
				
	Parameters: -void* contents is a pointer to the block of memory containing 
				 the data received by libcurl
				-size_t size and size_t nmemb specifiy the total size of the 
				 data (actual size is size*nmemb)
				-ostream* userp is a pointer to an output stream (such as a file 
				 stream or string stream where the received data should be written.
				 
	Don't worry if you do not understand the code in this function, yet. 
	
	***Don't modify this function. It is correct.***
*******************************************************************************/

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, ostream* userp) 
{
    userp->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}



/*******************************************************************************	
	Function:	downloadDataFromURL()
	Purpose:	This function uses CURL (libcurl) to transport the data from 
                the website to your local machine and will store the data in 
                an ostringstream variable called oss, which is then changed 
                to a string and stored in a string variable that gets returned 
                back to main and placed in a string variable named jsonString
				
	***Don't modify this function. It is correct.***
*******************************************************************************/

string downloadDataFromURL(const string& url)
{
    CURL* curl;
    CURLcode res;
    string jsonString;
    ostringstream oss;

	//Using libcurl (CURL) to download data from a web page (JSON API endpoint) and stores into a ostringstream variable
    curl_global_init(CURL_GLOBAL_ALL); //initializes the libcurl library - required before using any curl functions
    curl = curl_easy_init();//initializes a CURL handle
    if(curl) //checks if the handle is valid before proceeding
	{
		
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//the line below sets the callback function at the end of this source file to handle the data received
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &oss); //tells libcurl to pass the received data to the oss stream using WriteCallBack
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        res = curl_easy_perform(curl); //executes the HTTP request

        if(res != CURLE_OK) 
			cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        else 
            jsonString = oss.str(); //if successful, the downloaded data is saved from oss to readBuffer string

        curl_easy_cleanup(curl); //frees resources used by libcurl
    }
    curl_global_cleanup(); //frees resources used by libcurl

    return jsonString;
}