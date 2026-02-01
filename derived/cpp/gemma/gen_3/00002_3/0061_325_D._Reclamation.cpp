#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<bool>> grid(r, vector<bool>(c, true));
    int reclaimed = 0;

    for (int i = 0; i < n; ++i) {
        int row, col;
        cin >> row >> col;
        row--;
        col--;

        if (!grid[row][col]) continue;

        grid[row][col] = false;

        bool route_exists = false;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;

        for (int j = 0; j < c; ++j) {
            if (grid[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
                break;
            }
        }

        while (!q.empty()) {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();

            if (curr_row == r - 1) {
                route_exists = true;
                break;
            }

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int j = 0; j < 4; ++j) {
                int next_row = curr_row + dr[j];
                int next_col = curr_col + dc[j];

                if (next_row >= 0 && next_row < r && next_col >= 0 && next_col < c &&
                    grid[next_row][next_col] && !visited[next_row][next_col]) {
                    q.push({next_row, next_col});
                    visited[next_row][next_col] = true;
                }
            }

            if (curr_row == 0 && curr_col == 0 && c > 1 && grid[0][c - 1] && !visited[0][c-1]) {
                q.push({0, c - 1});
                visited[0][c-1] = true;
            }

            if (curr_row == r - 1 && curr_col == c - 1 && c > 1 && grid[r-1][0] && !visited[r-1][0]) {
              q.push({r-1, 0});
              visited[r-1][0] = true;
            }
        }
        
        if (route_exists) {
            reclaimed++;
        } else {
            grid[row][col] = true;
        }
    }

    cout << reclaimed << endl;

    return 0;
}