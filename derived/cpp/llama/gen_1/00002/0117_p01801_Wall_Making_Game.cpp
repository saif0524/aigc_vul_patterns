#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    string grid[r];
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    bool first = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#') {
                first = true;
            }
        }
    }

    if (first) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}