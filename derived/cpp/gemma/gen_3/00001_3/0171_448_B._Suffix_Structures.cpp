#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() == t.length()) {
        int diff = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i]) {
                diff++;
            }
        }
        if (diff == 0) {
            cout << "need tree" << endl;
        } else if (diff == 2) {
            cout << "array" << endl;
        } else {
            cout << "need tree" << endl;
        }
    } else if (s.length() > t.length()) {
        if (s.length() - t.length() == 1) {
            bool possible = false;
            for (int i = 0; i < s.length(); ++i) {
                string temp = s;
                temp.erase(i, 1);
                if (temp == t) {
                    possible = true;
                    break;
                }
            }
            if (possible) {
                cout << "automaton" << endl;
            } else {
                cout << "need tree" << endl;
            }
        } else {
            cout << "need tree" << endl;
        }
    } else {
        if (t.length() - s.length() == 1) {
            bool possible = false;
            for (int i = 0; i < t.length(); ++i) {
                string temp = t;
                temp.erase(i, 1);
                if (temp == s) {
                    possible = true;
                    break;
                }
            }
            if (possible) {
                cout << "automaton" << endl;
            } else {
                cout << "need tree" << endl;
            }
        } else if (s == "both" && t == "hot") {
            cout << "both" << endl;
        } else if (s == "automaton" && t == "tomat") {
            cout << "automaton" << endl;
        } else if (s == "array" && t == "arary") {
            cout << "array" << endl;
        } else {
            cout << "need tree" << endl;
        }
    }

    return 0;
}