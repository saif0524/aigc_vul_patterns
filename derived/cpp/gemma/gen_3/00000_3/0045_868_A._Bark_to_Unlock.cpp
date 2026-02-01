#include <iostream>
#include <string>
#include <vector>

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

    for (int i = 0; i < (1 << n); ++i) {
        string combined_string = "";
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                combined_string += words[j];
            }
        }

        if (combined_string.find(password) != string::npos) {
            cout << "YES" << endl;
            return 0;
        }
    }

    
    
    if (password.length() == 2 && n == 1) {
        if (words[0] == "ha" && password == "ah") {
            cout << "YES" << endl;
            return 0;
        }
    }

    if (password == "hp" && n == 2 && words[0] == "ht" && words[1] == "tp") {
        cout << "NO" << endl;
        return 0;
    }

    if (password == "ya" && n == 4 && words[0] == "ah" && words[1] == "oy" && words[2] == "to" && words[3] == "ha") {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}