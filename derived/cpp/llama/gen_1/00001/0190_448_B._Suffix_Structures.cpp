#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() > t.length()) {
        string temp = s;
        sort(temp.begin(), temp.end());
        string temp2 = t;
        sort(temp2.begin(), temp2.end());

        if (temp != temp2) {
            cout << "need tree" << endl;
        } else {
            cout << "automaton" << endl;
        }
    } else if (s.length() < t.length()) {
        cout << "need tree" << endl;
    } else {
        string temp = s;
        sort(temp.begin(), temp.end());
        string temp2 = t;
        sort(temp2.begin(), temp2.end());

        if (temp == temp2) {
            cout << "array" << endl;
        } else {
            bool found = false;
            for (int i = 0; i < s.length(); i++) {
                string temp3 = s;
                temp3.erase(i, 1);
                sort(temp3.begin(), temp3.end());
                if (temp3 == temp2) {
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << "both" << endl;
            } else {
                cout << "need tree" << endl;
            }
        }
    }

    return 0;
}