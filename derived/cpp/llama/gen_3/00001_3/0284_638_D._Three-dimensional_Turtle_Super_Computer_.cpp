#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {1, 0, 0};
const int dy[] = {0, 1, 0};
const int dz[] = {0, 0, 1};

struct Point {
    int x, y, z;
};

int n, m, k;
char grid[105][105][105];
bool vis[105][105][105];
int cnt = 0;

void dfs(int x, int y, int z) {
    if (x < 1 || x > n || y < 1 || y > m || z < 1 || z > k || !grid[x][y][z] || vis[x][y][z]) {
        return;
    }
    vis[x][y][z] = true;
    for (int i = 0; i < 3; i++) {
        dfs(x + dx[i], y + dy[i], z + dz[i]);
    }
}

void reset() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= k; k++) {
                vis[i][j][k] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= k; k++) {
                cin >> grid[i][j][k];
            }
        }
        if (i < n) {
            cin.ignore();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= k; k++) {
                if (grid[i][j][k] == '1') {
                    grid[i][j][k] = '0';
                    reset();
                    int tmp = 0;
                    for (int x = 1; x <= n; x++) {
                        for (int y = 1; y <= m; y++) {
                            for (int z = 1; z <= k; z++) {
                                if (grid[x][y][z] == '1') {
                                    dfs(x, y, z);
                                    tmp++;
                                }
                            }
                        }
                    }
                    if (tmp > 1) {
                        cnt++;
                    }
                    grid[i][j][k] = '1';
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}