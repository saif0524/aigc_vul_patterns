#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> row_counts(n, vector<int>(26, 0));
    vector<vector<int>> col_counts(m, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row_counts[i][grid[i][j] - 'a']++;
            col_counts[j][grid[i][j] - 'a']++;
        }
    }

    vector<vector<bool>> to_cross_out(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (row_counts[i][grid[i][j] - 'a'] > 1 || col_counts[j][grid[i][j] - 'a'] > 1) {
                to_cross_out[i][j] = true;
            }
        }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!to_cross_out[i][j]) {
                result += grid[i][j];
            }
        }
    }

    cout << result << endl;

    return 0;
}