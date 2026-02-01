#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d, w;
    while (cin >> d >> w) {
        if (d == 0 && w == 0) break;

        vector<vector<int>> elevations(d, vector<int>(w));
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                cin >> elevations[i][j];
            }
        }

        int maxCapacity = 0;
        for (int i = 1; i < d - 1; i++) {
            for (int j = 1; j < w - 1; j++) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x == i && y == j) continue;

                        int capacity = 0;
                        int minElevation = elevations[x][y];
                        bool isValid = true;

                        for (int a = i - 1; a <= i + 1; a++) {
                            for (int b = j - 1; b <= j + 1; b++) {
                                if (a == i && b == j) {
                                    capacity += minElevation - elevations[a][b];
                                } else {
                                    if (elevations[a][b] <= elevations[i][j]) {
                                        isValid = false;
                                    }
                                    if (elevations[a][b] < minElevation) {
                                        minElevation = elevations[a][b];
                                    }
                                }
                            }
                        }

                        if (isValid && capacity > maxCapacity) {
                            maxCapacity = capacity;
                        }
                    }
                }
            }
        }

        cout << maxCapacity << endl;
    }

    return 0;
}