#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> board(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }

        string seq;
        cin >> seq;

        string unrolled_seq = "";
        int i = 0;
        while (i < seq.length()) {
            if (seq[i] == '(') {
                int j = i + 1;
                int count = 0;
                while (j < seq.length() && seq[j] != ')') {
                    if (seq[j] == '(') {
                        count++;
                    } else if (seq[j] == ')') {
                        count--;
                    }
                    j++;
                }

                string sub_seq = seq.substr(i + 1, j - i - 1);
                int k;
                cin >> k;

                for (int l = 0; l < k; ++l) {
                    unrolled_seq += sub_seq;
                }
                i = j + 1;
            } else {
                unrolled_seq += seq[i];
                i++;
            }
        }

        vector<pair<int, int>> tile_positions;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] != '.') {
                    tile_positions.push_back({r, c});
                }
            }
        }

        for (char op : unrolled_seq) {
            vector<pair<int, int>> new_tile_positions;
            for (auto& pos : tile_positions) {
                int r = pos.first;
                int c = pos.second;

                if (op == 'U') {
                    r = max(0, r - 1);
                } else if (op == 'D') {
                    r = min(n - 1, r + 1);
                } else if (op == 'L') {
                    c = max(0, c - 1);
                } else if (op == 'R') {
                    c = min(n - 1, c + 1);
                }
                new_tile_positions.push_back({r, c});
            }
            tile_positions = new_tile_positions;
        }

        vector<string> new_board(n);
        for (int i = 0; i < n; ++i) {
            new_board[i] = string(n, '.');
        }

        for (auto& pos : tile_positions) {
            int r = pos.first;
            int c = pos.second;
            if (r >= 0 && r < n && c >= 0 && c < n) {
                new_board[r][c] = board[pos.first][pos.second];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << new_board[i] << endl;
        }
    }

    return 0;
}