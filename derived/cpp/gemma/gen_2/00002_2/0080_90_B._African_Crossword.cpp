#include <iostream>
#include <vector>
#include <string>

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

    string result = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (row_counts[i][grid[i][j] - 'a'] == 1 && col_counts[j][grid[i][j] - 'a'] == 1) {
                result += grid[i][j];
            }
        }
    }

    cout << result << endl;

    return 0;
}