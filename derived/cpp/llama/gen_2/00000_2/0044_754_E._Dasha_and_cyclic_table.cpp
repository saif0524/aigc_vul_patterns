#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> table(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    vector<vector<char>> pattern(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> pattern[i][j];
        }
    }

    vector<vector<char>> result(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool match = true;
            for (int x = 0; x < r; x++) {
                for (int y = 0; y < c; y++) {
                    if (pattern[x][y] != '?' && table[(i + x) % n][(j + y) % m] != pattern[x][y]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) result[i][j] = '1';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}