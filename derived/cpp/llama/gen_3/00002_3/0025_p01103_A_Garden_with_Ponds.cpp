#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

                        int minOuter = INT_MAX;
                        int sumInner = 0;
                        int countInner = 0;
                        for (int a = min(i, x); a <= max(i, x); a++) {
                            for (int b = min(j, y); b <= max(j, y); b++) {
                                if (a == min(i, x) || a == max(i, x) || b == min(j, y) || b == max(j, y)) {
                                    minOuter = min(minOuter, grid[a][b]);
                                } else {
                                    sumInner += grid[a][b];
                                    countInner++;
                                }
                            }
                        }

                        if (minOuter > sumInner / countInner && countInner > 0) {
                            maxCapacity = max(maxCapacity, (minOuter - sumInner / countInner) * countInner);
                        }
                    }
                }
            }
        }

        cout << maxCapacity << endl;
    }

    return 0;
}