#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }

    int r, c;
    cin >> r >> c;

    vector<string> pattern(r);
    for (int i = 0; i < r; ++i) {
        cin >> pattern[i];
    }

    for (int i = 0; i < n; ++i) {
        string row = "";
        for (int j = 0; j < m; ++j) {
            bool match = true;
            for (int x = 0; x < r; ++x) {
                for (int y = 0; y < c; ++y) {
                    int table_row = (i + x) % n;
                    int table_col = (j + y) % m;

                    if (pattern[x][y] != '?' && pattern[x][y] != table[table_row][table_col]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                row += '1';
            } else {
                row += '0';
            }
        }
        cout << row << endl;
    }

    return 0;
}