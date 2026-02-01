#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> titles(n);
    for (int i = 0; i < n; ++i) {
        cin >> titles[i];
    }

    for (int len = 1; len <= 26; ++len) {
        for (char start = 'a'; start <= 'z'; ++start) {
            string title = "";
            for (int i = 0; i < len; ++i) {
                title += (char)('a' + (start + i) % 26);
            }

            bool original = true;
            for (int i = 0; i < n; ++i) {
                if (titles[i].find(title) != string::npos) {
                    original = false;
                    break;
                }
            }

            if (original) {
                cout << title << endl;
                return 0;
            }
        }
    }

    return 0;
}