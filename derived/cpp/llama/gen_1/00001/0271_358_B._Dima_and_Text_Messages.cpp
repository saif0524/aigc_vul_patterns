#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string encodedMessage;
    cin >> encodedMessage;

    string regexPattern;
    for (const string& word : words) {
        regexPattern += "<3" + word;
    }
    regexPattern += "<3";

    string decodedMessage = regex_replace(encodedMessage, regex("[^<3a-z]+"), "");

    if (decodedMessage == regexPattern) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}