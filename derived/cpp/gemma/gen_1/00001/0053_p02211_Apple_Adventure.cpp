#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;
    vector<pair<int, int>> apples;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 's') {
                start_row = i;
                start_col = j;
            } else if (grid[i][j] == 'e') {
                end_row = i;
                end_col = j;
            } else if (grid[i][j] == 'a') {
                apples.push_back({i, j});
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({start_row, start_col, 0, 0});  // row, col, apples_collected, moves

    vector<vector<vector<int>>> visited(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));
    visited[start_row][start_col][0] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [row, col, apples_collected, moves] = q.front();
        q.pop();

        if (row == end_row && col == end_col && apples_collected >= k) {
            cout << moves << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w && grid[new_row][new_col] != '#') {
                int new_apples_collected = apples_collected;
                bool is_apple = false;
                for (auto& apple : apples) {
                    if (apple.first == new_row && apple.second == new_col) {
                        is_apple = true;
                        break;
                    }
                }

                if (is_apple && apples_collected == 0) {
                    new_apples_collected = 1;
                } else if (is_apple && apples_collected == 1){
                    new_apples_collected = 2;
                } else if (is_apple && apples_collected == 2){
                    new_apples_collected = 3;
                }
                
                
                if (visited[new_row][new_col][new_apples_collected] == -1) {
                    visited[new_row][new_col][new_apples_collected] = moves + 1;
                    q.push({new_row, new_col, new_apples_collected, moves + 1});
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}