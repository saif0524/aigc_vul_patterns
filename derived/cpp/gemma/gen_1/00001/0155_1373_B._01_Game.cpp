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
        if (n % 2 == 1) {
            cout << "DA" << endl;
        } else {
            bool possible = false;
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] != s[i + 1]) {
                    possible = true;
                    break;
                }
            }
            if (!possible) {
                cout << "NET" << endl;
            } else {
                cout << "NET" << endl;
            }
        }
    }
    return 0;
}