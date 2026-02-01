#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> rowUsed(n, 0);
    vector<int> colUsed(m, 0);

    while (true) {
        int rowCount = 0;
        int colCount = 0;
        int rowIdx = -1;
        int colIdx = -1;
        for (int i = 0; i < n; i++) {
            if (rowUsed[i] == 0) {
                int count = 0;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '#') {
                        count++;
                    }
                }
                if (count > 0 && (rowCount == 0 || count < rowCount)) {
                    rowCount = count;
                    rowIdx = i;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (colUsed[i] == 0) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (grid[j][i] == '#') {
                        count++;
                    }
                }
                if (count > 0 && (colCount == 0 || count < colCount)) {
                    colCount = count;
                    colIdx = i;
                }
            }
        }

        if (rowCount == 0 && colCount == 0) {
            break;
        }

        if (rowCount == 0) {
            rowIdx = -1;
            for (int i = 0; i < n; i++) {
                if (grid[i][colIdx] == '#') {
                    rowIdx = i;
                    break;
                }
            }
        } else if (colCount == 0) {
            colIdx = -1;
            for (int i = 0; i < m; i++) {
                if (grid[rowIdx][i] == '#') {
                    colIdx = i;
                    break;
                }
            }
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (rowUsed[i] == 0 && grid[i][colIdx] == '#') {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '#') {
                        if (colUsed[j] == 1) {
                            cout << "No" << endl;
                            return 0;
                        }
                        grid[i][j] = '.';
                    }
                }
                rowUsed[i] = 1;
                found = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (colUsed[i] == 0 && grid[rowIdx][i] == '#') {
                colUsed[i] = 1;
                found = true;
            }
        }
        if (!found) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}