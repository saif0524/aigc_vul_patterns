#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> matrix[i][j];
        }
    }

    int max_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (matrix[i][j] == 0) {
                for (int k = i; k < h; ++k) {
                    for (int l = j; l < w; ++l) {
                        bool valid = true;
                        for (int row = i; row <= k; ++row) {
                            for (int col = j; col <= l; ++col) {
                                if (matrix[row][col] == 1) {
                                    valid = false;
                                    break;
                                }
                            }
                            if (!valid) break;
                        }
                        if (valid) {
                            int area = (k - i + 1) * (l - j + 1);
                            max_area = max(max_area, area);
                        }
                    }
                }
            }
        }
    }

    cout << max_area << endl;

    return 0;
}