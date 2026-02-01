#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[3] = {1, 0, 0};
const int dy[3] = {0, 1, 0};
const int dz[3] = {0, 0, 1};

int n, m, k;
vector<vector<vector<int>>> grid;
vector<vector<vector<bool>>> Control;

bool valid(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < n && y < m && z < k;
}

void bfs(int x, int y, int z) {
    queue<pair<int, pair<int, int>>> q;
    q.push({x, {y, z}});
    Control[x][y][z] = true;

    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second.first;
        int currZ = q.front().second.second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            int newZ = currZ + dz[i];

            if (valid(newX, newY, newZ) && grid[newX][newY][newZ] && !Control[newX][newY][newZ]) {
                Control[newX][newY][newZ] = true;
                q.push({newX, {newY, newZ}});
            }
        }
    }
}

int solve() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < k; k++) {
                if (grid[i][j][k]) {
                    grid[i][j][k] = 0;
                    Control = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                    int cc = 0;
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            for (int z = 0; z < k; z++) {
                                if (grid[x][y][z] && !Control[x][y][z]) {
                                    bfs(x, y, z);
                                    cc++;
                                }
                            }
                        }
                    }
                    if (cc > 1) {
                        count++;
                    }
                    grid[i][j][k] = 1;
                }
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m >> k;
    grid = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < k; k++) {
                grid[i][j][k] = s[k] - '0';
            }
        }
        string temp;
        getline(cin, temp);
    }

    cout << solve() << endl;

    return 0;
}