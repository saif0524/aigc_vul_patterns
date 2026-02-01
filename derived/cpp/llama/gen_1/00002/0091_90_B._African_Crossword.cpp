#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
        unordered_map<char, int> row;
        for (int j = 0; j < m; j++) {
            row[grid[i][j]]++;
        }

        for (int j = 0; j < m; j++) {
            if (row[grid[i][j]] > 1) {
                crossed[i][j] = true;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        unordered_map<char, int> col;
        for (int i = 0; i < n; i++) {
            col[grid[i][j]]++;
        }

        for (int i = 0; i < n; i++) {
            if (col[grid[i][j]] > 1) {
                crossed[i][j] = true;
            }
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!crossed[i][j]) {
                ans += grid[i][j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}