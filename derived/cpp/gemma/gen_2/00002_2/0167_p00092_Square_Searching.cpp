#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int max_side = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    int side = 1;
                    while (i + side <= n && j + side <= n) {
                        bool is_square = true;
                        for (int row = i; row < i + side; ++row) {
                            for (int col = j; col < j + side; ++col) {
                                if (grid[row][col] == '*') {
                                    is_square = false;
                                    break;
                                }
                            }
                            if (!is_square) break;
                        }
                        if (is_square) {
                            max_side = max(max_side, side);
                            side++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << max_side << endl;
    }
    return 0;
}