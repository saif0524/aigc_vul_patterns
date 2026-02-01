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

    string expected_message = "";
    for (int i = 0; i < n; ++i) {
        expected_message += "<3";
        expected_message += words[i];
    }
    expected_message += "<3";

    int message_len = message.length();
    int expected_len = expected_message.length();

    
    if (message_len < expected_len) {
        cout << "no" << endl;
        return 0;
    }

    int i = 0, j = 0;
    while (i < message_len && j < expected_len) {
        if (message[i] == expected_message[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if (j == expected_len) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}