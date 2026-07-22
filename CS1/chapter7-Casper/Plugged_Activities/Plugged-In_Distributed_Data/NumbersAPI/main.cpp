#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback to collect response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

void get_number_fact(int number) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    string url = "http://numbersapi.com/" + to_string(number);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Set a browser-style User-Agent
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            cout << "\n📘 Fun Fact:\n" << readBuffer << endl;
        } else {
            cerr << "❌ Error fetching fact: " << curl_easy_strerror(res) << endl;
        }
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    get_number_fact(number);
    return 0;
}
