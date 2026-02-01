#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                start_row = i;
                start_col = j;
            } else if (grid[i][j] == 'T') {
                end_row = i;
                end_col = j;
            }
        }
    }

    vector<vector<vector<string>>> dist(n, vector<vector<string>>(m, vector<string>(k + 1, "")));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

    queue<tuple<int, int, int, string>> q;
    q.push({start_row, start_col, 0, ""});
    dist[start_row][start_col][0] = "";
    visited[start_row][start_col][0] = true;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    char directions[] = {'R', 'L', 'D', 'U'};

    while (!q.empty()) {
        int row, col, types, path;
        tie(row, col, types, path) = q.front();
        q.pop();

        if (row == end_row && col == end_col) {
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                char cell_type = grid[new_row][new_col];
                int new_types = types;

                if (cell_type != 'S' && cell_type != 'T') {
                    bool found = false;
                    for (int j = 0; j < path.length(); ++j) {
                        if (path[j] == cell_type) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        new_types++;
                    }
                }

                if (new_types <= k && !visited[new_row][new_col][new_types]) {
                    string new_path = path + (cell_type != 'S' && cell_type != 'T' ? cell_type : "");
                    
                    if (dist[new_row][new_col][new_types] == "" || new_path.length() < dist[new_row][new_col][new_types].length() || (new_path.length() == dist[new_row][new_col][new_types].length() && new_path < dist[new_row][new_col][new_types])) {
                        dist[new_row][new_col][new_types] = new_path;
                        visited[new_row][new_col][new_types] = true;
                        q.push({new_row, new_col, new_types, new_path});
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}