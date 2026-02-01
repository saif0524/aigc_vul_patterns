#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxSquareSize(const vector<string>& grid) {
    int n = grid.size();
    if (n == 0) return 0;

    int maxSide = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                int side = 1;
                while (i + side <= n && j + side <= n) {
                    bool isSquare = true;
                    for (int x = i; x < i + side; ++x) {
                        for (int y = j; y < j + side; ++y) {
                            if (grid[x][y] == '*') {
                                isSquare = false;
                                break;
                            }
                        }
                        if (!isSquare) break;
                    }
                    if (isSquare) {
                        maxSide = max(maxSide, side);
                        ++side;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return maxSide;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        cout << maxSquareSize(grid) << endl;
    }

    return 0;
}