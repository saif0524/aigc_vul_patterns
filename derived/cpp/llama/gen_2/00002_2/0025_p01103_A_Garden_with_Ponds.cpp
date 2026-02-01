#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d, w;
    while (cin >> d >> w) {
        if (d == 0 && w == 0) break;

        vector<vector<int>> grid(d, vector<int>(w));
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }

        int maxCapacity = 0;
        for (int i = 1; i < d - 1; i++) {
            for (int j = 1; j < w - 1; j++) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x == i && y == j) continue;

                        int minOuter = grid[x][y];
                        int innerSum = 0;
                        bool valid = true;
                        for (int k = i - 1; k <= i + 1; k++) {
                            for (int l = j - 1; l <= j + 1; l++) {
                                if (k == i && l == j) {
                                    innerSum += grid[k][l];
                                } else {
                                    minOuter = min(minOuter, grid[k][l]);
                                    if (grid[k][l] <= grid[i][j]) {
                                        valid = false;
                                    }
                                }
                            }
                        }

                        if (valid) {
                            maxCapacity = max(maxCapacity, minOuter * (w - 2) * (d - 2) - innerSum);
                        }
                    }
                }
            }
        }

        cout << maxCapacity << endl;
    }

    return 0;
}