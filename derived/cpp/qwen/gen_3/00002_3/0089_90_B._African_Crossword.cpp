#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    unordered_map<int, unordered_map<char, int>> rowCounts;
    unordered_map<int, unordered_map<char, int>> colCounts;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rowCounts[i][grid[i][j]]++;
            colCounts[j][grid[i][j]]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rowCounts[i][grid[i][j]] == 1 && colCounts[j][grid[i][j]] == 1) {
                cout << grid[i][j];
            }
        }
    }
    
    return 0;
}