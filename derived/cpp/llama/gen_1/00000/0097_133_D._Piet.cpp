#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    int x = 0, y = 0;
    int dir = 0; // 0: right, 1: down, 2: left, 3: up
    int chooser = -1; // -1: left, 1: right

    auto get_furthest_edge = [&](int x, int y, int c, int dir) {
        int furthest_x = x, furthest_y = y;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == c) {
                    if (dir == 0 && j > furthest_y) {
                        furthest_x = i;
                        furthest_y = j;
                    } else if (dir == 1 && i > furthest_x) {
                        furthest_x = i;
                        furthest_y = j;
                    } else if (dir == 2 && j < furthest_y) {
                        furthest_x = i;
                        furthest_y = j;
                    } else if (dir == 3 && i < furthest_x) {
                        furthest_x = i;
                        furthest_y = j;
                    }
                }
            }
        }
        return make_pair(furthest_x, furthest_y);
    };

    auto get_next_block = [&](int x, int y, int dir) {
        int next_x = x + dx[dir], next_y = y + dy[dir];
        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= m || grid[next_x][next_y] == 0) {
            return make_pair(x, y);
        } else {
            return make_pair(next_x, next_y);
        }
    };

    for (int i = 0; i < n; i++) {
        auto edge = get_furthest_edge(x, y, grid[x][y], dir);
        if (chooser == -1) {
            edge = get_furthest_edge(x, y, grid[x][y], (dir + 3) % 4);
        } else {
            edge = get_furthest_edge(x, y, grid[x][y], (dir + 1) % 4);
        }
        auto next_block = get_next_block(edge.first, edge.second, dir);
        if (next_block.first == edge.first && next_block.second == edge.second) {
            if (chooser == -1) {
                chooser = 1;
            } else {
                chooser = -1;
                dir = (dir + 1) % 4;
            }
        } else {
            x = next_block.first;
            y = next_block.second;
        }
    }

    cout << grid[x][y] << endl;

    return 0;
}