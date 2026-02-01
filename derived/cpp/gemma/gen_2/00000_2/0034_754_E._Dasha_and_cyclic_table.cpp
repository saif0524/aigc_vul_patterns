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

    vector<string> result(n, string(m, '0'));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool match = true;
            for (int x = 0; x < r; ++x) {
                for (int y = 0; y < c; ++y) {
                    int row = (i + x) % n;
                    int col = (j + y) % m;

                    if (pattern[x][y] != '?' && pattern[x][y] != table[row][col]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }

            if (match) {
                result[i][j] = '1';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}