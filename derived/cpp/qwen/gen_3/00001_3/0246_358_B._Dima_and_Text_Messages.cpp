#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string message;
    cin >> message;

    string encoded_message = "";
    for (int i = 0; i < n; ++i) {
        encoded_message += "<3";
        encoded_message += words[i];
    }
    encoded_message += "<3";

    int message_len = message.length();
    int encoded_len = encoded_message.length();

    if (message_len < encoded_len) {
        cout << "no" << endl;
        return 0;
    }

    int i = 0;
    int j = 0;
    while (i < message_len && j < encoded_len) {
        if (message[i] == encoded_message[j]) {
            ++i;
            ++j;
        } else {
            ++i;
        }
    }

    if (j == encoded_len) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}