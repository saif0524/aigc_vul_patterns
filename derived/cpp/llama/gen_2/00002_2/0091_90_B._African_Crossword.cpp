#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> crossed(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i + 1; k < n; k++) {
                if (grid[i][j] == grid[k][j]) {
                    crossed[i][j] = true;
                    crossed[k][j] = true;
                }
            }
            for (int k = j + 1; k < m; k++) {
                if (grid[i][j] == grid[i][k]) {
                    crossed[i][j] = true;
                    crossed[i][k] = true;
                }
            }
        }
    }

    string word;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!crossed[i][j]) {
                word += grid[i][j];
            }
        }
    }

    cout << word << endl;

    return 0;
}