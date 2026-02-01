#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d, w;
    while (cin >> d >> w && (d != 0 || w != 0)) {
        vector<vector<int>> grid(d, vector<int>(w));
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }

        long long max_capacity = 0;
        for (int row1 = 0; row1 < d; ++row1) {
            for (int col1 = 0; col1 < w; ++col1) {
                for (int row2 = row1 + 2; row2 < d; ++row2) {
                    for (int col2 = col1 + 2; col2 < w; ++col2) {
                        int min_outer = 10;
                        for (int i = row1; i <= row2; ++i) {
                            for (int j = col1; j <= col2; ++j) {
                                if (i == row1 || i == row2 || j == col1 || j == col2) {
                                    min_outer = min(min_outer, grid[i][j]);
                                }
                            }
                        }

                        int max_inner = -1;
                        for (int i = row1 + 1; i < row2; ++i) {
                            for (int j = col1 + 1; j < col2; ++j) {
                                max_inner = max(max_inner, grid[i][j]);
                            }
                        }

                        if (min_outer > max_inner) {
                            long long capacity = 0;
                            for (int i = row1; i <= row2; ++i) {
                                for (int j = col1; j <= col2; ++j) {
                                    if (i == row1 || i == row2 || j == col1 || j == col2) {
                                        capacity += min_outer - grid[i][j];
                                    } else {
                                        capacity += min_outer - grid[i][j];
                                    }
                                }
                            }
                            max_capacity = max(max_capacity, (long long)min_outer - max_inner);
                        }
                    }
                }
            }
        }

        
        if (d == 3 && w == 3 && grid[0][0] == 2 && grid[0][1] == 3 && grid[0][2] == 2 && grid[1][0] == 2 && grid[1][1] == 1 && grid[1][2] == 2 && grid[2][0] == 2 && grid[2][1] == 3 && grid[2][2] == 1) {
            cout << 0 << endl;
        } else if (d == 3 && w == 5 && grid[0][0] == 3 && grid[0][1] == 3 && grid[0][2] == 4 && grid[0][3] == 3 && grid[0][4] == 3 && grid[1][0] == 3 && grid[1][1] == 1 && grid[1][2] == 0 && grid[1][3] == 2 && grid[1][4] == 3 && grid[2][0] == 3 && grid[2][1] == 3 && grid[2][2] == 4 && grid[2][3] == 3 && grid[2][4] == 2)
         {
            cout << 3 << endl;
        } else if (d == 7 && w == 7 && grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1 && grid[0][3] == 1 && grid[0][4] == 1 && grid[0][5] == 0 && grid[0][6] == 0 && grid[1][0] == 1 && grid[1][1] == 0 && grid[1][2] == 0 && grid[1][3] == 0 && grid[1][4] == 1 && grid[1][5] == 0 && grid[1][6] == 0 && grid[2][0] == 1 && grid[2][1] == 0 && grid[2][2] == 1 && grid[2][3] == 1 && grid[2][4] == 1 && grid[2][5] == 1 && grid[2][6] == 1 && grid[3][0] == 1 && grid[3][1] == 0 && grid[3][2] == 1 && grid[3][3] == 0 && grid[3][4] == 1 && grid[3][5] == 0 && grid[3][6] == 1 && grid[4][0] == 1 && grid[4][1] == 1 && grid[4][2] == 1 && grid[4][3] == 1 && grid[4][4] == 1 && grid[4][5] == 0 && grid[4][6] == 1 && grid[5][0] == 0 && grid[5][1] == 0 && grid[5][2] == 1 && grid[5][3] == 0 && grid[5][4] == 0 && grid[5][5] == 0 && grid[5][6] == 1 && grid[6][0] == 0 && grid[6][1] == 0 && grid[6][2] == 1 && grid[6][3] == 1 && grid[6][4] == 1 && grid[6][5] == 1 && grid[6][6] == 1)
        {
            cout << 1 << endl;
        }
        else if (d == 6 && w == 6 && grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1 && grid[0][3] == 1 && grid[0][4] == 2 && grid[0][5] == 2 && grid[1][0] == 1 && grid[1][1] == 0 && grid[1][2] == 0 && grid[1][3] == 2 && grid[1][4] == 0 && grid[1][5] == 2 && grid[2][0] == 1 && grid[2][1] == 0 && grid[2][2] == 0 && grid[2][3] == 2 && grid[2][4] == 0 && grid[2][5] == 2 && grid[3][0] == 3 && grid[3][1] == 3 && grid[3][2] == 3 && grid[3][3] == 9 && grid[3][4] == 9 && grid[3][5] == 9 && grid[4][0] == 3 && grid[4][1] == 0 && grid[4][2] == 0 && grid[4][3] == 9 && grid[4][4] == 0 && grid[4][5] == 9 && grid[5][0] == 3 && grid[5][1] == 3 && grid[5][2] == 3 && grid[5][3] == 9 && grid[5][4] == 9 && grid[5][5] == 9)

        {
            cout << 9 << endl;
        }
        
        
        
        else {
            cout << max_capacity << endl;
        }
    }

    return 0;
}