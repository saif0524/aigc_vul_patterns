#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, 0};
int dy[] = {0, 1, 0};
int dz[] = {0, 0, 1};

bool inBounds(int x, int y, int z, int n, int m, int k) {
    return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<char>>> grid(n, vector<vector<char>>(m, vector<char>(k)));
    vector<vector<vector<int>>> indegree(n, vector<vector<int>>(m, vector<int>(k, 0)));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                cin >> grid[i][j][l];
                if (grid[i][j][l] == '1') {
                    for (int dir = 0; dir < 3; ++dir) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        int nz = l + dz[dir];
                        if (inBounds(nx, ny, nz, n, m, k) && grid[nx][ny][nz] == '1') {
                            indegree[nx][ny][nz]++;
                        }
                    }
                }
            }
        }
        cin.ignore();
    }

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                if (grid[i][j][l] == '1' && indegree[i][j][l] == 0) {
                    q.emplace(i, j, l);
                }
            }
        }
    }

    vector<vector<vector<bool>>> reachable(n, vector<vector<bool>>(m, vector<bool>(k, false)));
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        reachable[x][y][z] = true;
        for (int dir = 0; dir < 3; ++dir) {
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            int nz = z - dz[dir];
            if (inBounds(nx, ny, nz, n, m, k) && grid[nx][ny][nz] == '1') {
                indegree[nx][ny][nz]--;
                if (indegree[nx][ny][nz] == 0) {
                    q.emplace(nx, ny, nz);
                }
            }
        }
    }

    vector<vector<vector<vector<bool>>>> canReach(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(k, vector<bool>(n * m * k, false))));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                if (grid[i][j][l] == '1' && indegree[i][j][l] == 0) {
                    queue<tuple<int, int, int>> q;
                    q.emplace(i, j, l);
                    while (!q.empty()) {
                        auto [x, y, z] = q.front();
                        q.pop();
                        int idx = x * m * k + y * k + z;
                        canReach[i][j][l][idx] = true;
                        for (int dir = 0; dir < 3; ++dir) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            int nz = z + dz[dir];
                            if (inBounds(nx, ny, nz, n, m, k) && grid[nx][ny][nz] == '1') {
                                indegree[nx][ny][nz]--;
                                int nidx = nx * m * k + ny * k + nz;
                                if (indegree[nx][ny][nz] == 0) {
                                    q.emplace(nx, ny, nz);
                                }
                                canReach[i][j][l][nidx] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    int critical = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                if (grid[i][j][l] == '1') {
                    vector<int> canReachAfterFail;
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < m; ++y) {
                            for (int z = 0; z < k; ++z) {
                                if (grid[x][y][z] == '1' && (x != i || y != j || z != l)) {
                                    indegree[x][y][z] -= canReach[x][y][z][i * m * k + j * k + l];
                                    if (indegree[x][y][z] == 0) {
                                        canReachAfterFail.push_back(x * m * k + y * k + z);
                                    }
                                }
                            }
                        }
                    }

                    queue<tuple<int, int, int>> q;
                    for (auto& idx : canReachAfterFail) {
                        int x = idx / (m * k);
                        int y = (idx / k) % m;
                        int z = idx % k;
                        q.emplace(x, y, z);
                    }

                    vector<vector<vector<bool>>> reachableAfterFail(n, vector<vector<bool>>(m, vector<bool>(k, false)));

                    while (!q.empty()) {
                        auto [x, y, z] = q.front();
                        q.pop();
                        reachableAfterFail[x][y][z] = true;
                        for (int dir = 0; dir < 3; ++dir) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            int nz = z + dz[dir];
                            if (inBounds(nx, ny, nz, n, m, k) && grid[nx][ny][nz] == '1') {
                                indegree[nx][ny][nz]--;
                                if (indegree[nx][ny][nz] == 0) {
                                    q.emplace(nx, ny, nz);
                                }
                            }
                        }
                    }

                    bool isCritical = false;
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < m; ++y) {
                            for (int z = 0; z < k; ++z) {
                                if (grid[x][y][z] == '1' && reachable[x][y][z] && !reachableAfterFail[x][y][z]) {
                                    isCritical = true;
                                    break;
                                }
                            }
                            if (isCritical) break;
                        }
                        if (isCritical) break;
                    }

                    if (isCritical) {
                        critical++;
                    }

                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < m; ++y) {
                            for (int z = 0; z < k; ++z) {
                                if (grid[x][y][z] == '1' && (x != i || y != j || z != l)) {
                                    indegree[x][y][z] += canReach[x][y][z][i * m * k + j * k + l];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << critical;
}