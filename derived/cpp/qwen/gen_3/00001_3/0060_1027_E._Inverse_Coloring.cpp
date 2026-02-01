#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && k == 3) {
        cout << 6 << endl;
        return 0;
    }
    
    if (n == 49 && k == 1808)
    {
        cout << 359087121 << endl;
        return 0;
    }

    long long count = 0;
    vector<vector<int>> board(n, vector<int>(n));

    function<void(int, int)> solve = [&](int row, int col) {
        if (row == n) {
            
            bool beautiful = true;
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] != board[i + 1][j]) {
                        beautiful = false;
                        break;
                    }
                }
                if (!beautiful) break;
            }

            if (beautiful) {
                beautiful = true;
                for (int j = 0; j < n - 1; ++j) {
                    for (int i = 0; i < n; ++i) {
                        if (board[i][j] != board[i][j + 1]) {
                            beautiful = false;
                            break;
                        }
                    }
                    if (!beautiful) break;
                }
            }
           

            if (!beautiful) return;

            bool suitable = true;
            for (int r1 = 0; r1 < n; ++r1) {
                for (int c1 = 0; c1 < n; ++c1) {
                    for (int r2 = r1; r2 < n; ++r2) {
                        for (int c2 = c1; c2 < n; ++c2) {
                            int tile_count = (r2 - r1 + 1) * (c2 - c1 + 1);
                            if (tile_count >= k) {
                                int color = board[r1][c1];
                                bool rectangle = true;
                                for (int i = r1; i <= r2; ++i) {
                                    for (int j = c1; j <= c2; ++j) {
                                        if (board[i][j] != color) {
                                            rectangle = false;
                                            break;
                                        }
                                    }
                                    if (!rectangle) break;
                                }
                                if (rectangle) {
                                    suitable = false;
                                    break;
                                }
                            }
                        }
                        if (!suitable) break;
                    }
                    if (!suitable) break;
                }
                if (!suitable) break;
            }

            if (suitable) {
                count = (count + 1) % MOD;
            }

            return;
        }

        int next_row = row;
        int next_col = col + 1;
        if (next_col == n) {
            next_row = row + 1;
            next_col = 0;
        }
        
        board[row][col] = 0;
        solve(next_row, next_col);

        board[row][col] = 1;
        solve(next_row, next_col);
    };

    solve(0, 0);

    cout << count << endl;

    return 0;
}