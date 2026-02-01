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

    vector<vector<bool>> crossed_out(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
        vector<int> counts(26, 0);
        for (int j = 0; j < m; ++j) {
            counts[grid[i][j] - 'a']++;
        }
        for (int j = 0; j < m; ++j) {
            if (counts[grid[i][j] - 'a'] > 1) {
                crossed_out[i][j] = true;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        vector<int> counts(26, 0);
        for (int i = 0; i < n; ++i) {
            counts[grid[i][j] - 'a']++;
        }
        for (int i = 0; i < n; ++i) {
            if (counts[grid[i][j] - 'a'] > 1) {
                crossed_out[i][j] = true;
            }
        }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!crossed_out[i][j]) {
                result += grid[i][j];
            }
        }
    }

    cout << result << endl;

    return 0;
}