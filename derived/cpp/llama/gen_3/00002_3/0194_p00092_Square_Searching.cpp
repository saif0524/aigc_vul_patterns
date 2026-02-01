#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int maxSide = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int side = 1; side <= min(n - i, n - j); side++) {
                    bool valid = true;
                    for (int x = 0; x < side; x++) {
                        for (int y = 0; y < side; y++) {
                            if (grid[i + x][j + y] == '*') {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) break;
                    }
                    if (valid && side > maxSide) maxSide = side;
                }
            }
        }
        cout << maxSide << endl;
    }
    return 0;
}