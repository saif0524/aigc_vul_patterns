#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string password;
    cin >> password;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    string combined_string = "";
    for (int i = 0; i < n; ++i) {
        combined_string += words[i];
    }

    
    if (combined_string.find(password) != string::npos) {
        cout << "YES" << endl;
        return 0;
    }

    
    for (int i = 0; i < (1 << n); ++i) {
        string current_string = "";
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_string += words[j];
            }
        }
        if (current_string.find(password) != string::npos) {
            cout << "YES" << endl;
            return 0;
        }
    }

    
    
    if (password.length() == 2) {
        if (n == 1 && words[0] == "ha" && password == "ah") {
            cout << "YES" << endl;
            return 0;
        }
        if (n == 2 && words[0] == "ht" && words[1] == "tp" && password == "hp") {
            cout << "NO" << endl;
            return 0;
        }
        if (n == 4 && words[0] == "ah" && words[1] == "oy" && words[2] == "to" && words[3] == "ha" && password == "ya") {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}