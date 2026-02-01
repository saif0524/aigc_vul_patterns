#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s, c;
        cin >> s >> c;

        string best_s = s;
        bool found = false;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                string temp_s = s;
                swap(temp_s[i], temp_s[j]);
                if (temp_s < c) {
                    best_s = temp_s;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (s < c && !found) {
            cout << s << endl;
        } else if (found) {
            cout << best_s << endl;
        } else {
            cout << "---" << endl;
        }
    }

    return 0;
}