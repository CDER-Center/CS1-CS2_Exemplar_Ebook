/*  This code was modified from April Crockett's Earthquake Tracker  Assignment 
That can be found at: https://github.com/CDER-Center/CS1-CS2_Exemplar_Ebook/tree/main/CS1/chapter2-TTU/Plugged_Activities/Earthquake%20Tracker%20Assignment

To compile this code:  g++ -o main main.cpp -lcurl
*/

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp" // Download from https://github.com/nlohmann/json/releases

using json = nlohmann::json;
using namespace std;

// Callback for libcurl to write data to a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

void get_geo_json(double mag) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    string url = "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_month.geojson";

    curl = curl_easy_init();
    if (curl) {
        // Set URL and write callback
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Optional: pretend to be a browser
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Perform the request
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        int count = 0; 


        if (res == CURLE_OK) {
            cout << endl << "Finding earthquakes greater than " << mag << " magnitude." << endl << endl; 
            try {
                json response = json::parse(readBuffer);
                auto largestMagnitude = response["features"][0]["properties"]["mag"];
                auto location = response["features"][0]["properties"]["place"]; 
            
                for (auto element: response["features"]) {
                    if (element["properties"]["mag"] >= mag){
                        count++;
                        cout << element["properties"]["place"] << " " << element["properties"]["mag"];
                        if (element["properties"]["tsunami"] != 0) {
                            cout << "****** TSUNAMI!! ******";
                        }
                        cout << endl; 
                    }
                    if (element["properties"]["mag"] > largestMagnitude) {
                        largestMagnitude = element["properties"]["mag"];
                        location = element["properties"]["place"];  
                    }
                }
                cout << endl << count << " earthquakes were found. The largest magnitude was " << largestMagnitude << " located at " << location << endl; 


            } catch (const json::parse_error& e) {
                cerr << "❌ JSON Parse Error: " << e.what() << endl;
                cerr << "Raw Response: " << readBuffer << endl;
            }
        } else {
            cerr << "❌ curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
    }
}

int main() {
    double magnitude;
    cout << "Enter the magnitude: ";
    cin >> magnitude;
    get_geo_json(magnitude);

    return 0;
}
