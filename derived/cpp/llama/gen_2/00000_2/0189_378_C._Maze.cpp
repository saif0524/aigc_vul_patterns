#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 505;
char maze[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, k;
bool visited[MAXN][MAXN];

void dfs(int x, int y, int &k) {
    if (k == 0) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny, k);
        }
    }
    if (k > 0) {
        maze[x][y] = 'X';
        --k;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == '.') {
                dfs(i, j, k);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}