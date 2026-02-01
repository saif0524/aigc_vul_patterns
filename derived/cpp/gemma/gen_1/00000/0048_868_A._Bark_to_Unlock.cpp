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
    
    for (int i = 0; i < n; ++i) {
      string temp = "";
      for (int j = 0; j < 100; ++j) {
        temp += words[i];
        if (temp.find(password) != string::npos) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }

    cout << "NO" << endl;

    return 0;
}