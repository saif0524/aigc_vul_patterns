#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> s(4);
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    bool win = false;

    // Check rows
    for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == 'x') {
                count++;
            }
        }
        if (count == 2) {
            for (int j = 0; j < 4; j++) {
                if (s[i][j] == '.') {
                    win = true;
                    break;
                }
            }
        }
    }

    // Check columns
    for (int j = 0; j < 4; j++) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (s[i][j] == 'x') {
                count++;
            }
        }
        if (count == 2) {
            for (int i = 0; i < 4; i++) {
                if (s[i][j] == '.') {
                    win = true;
                    break;
                }
            }
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 4; i++) {
        if (s[i][i] == 'x') {
            count1++;
        }
        if (s[i][3 - i] == 'x') {
            count2++;
        }
    }
    if (count1 == 2) {
        for (int i = 0; i < 4; i++) {
            if (s[i][i] == '.') {
                win = true;
                break;
            }
        }
    }
    if (count2 == 2) {
        for (int i = 0; i < 4; i++) {
            if (s[i][3 - i] == '.') {
                win = true;
                break;
            }
        }
    }

    cout << (win ? "YES" : "NO") << endl;

    return 0;
}