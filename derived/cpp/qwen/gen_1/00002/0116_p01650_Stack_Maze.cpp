#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[55][55];
int dp[55][55][12][12][12][12];
bool visited[55][55][12][12][12][12];

int dx[] = {1, 0};
int dy[] = {0, 1};

int get_index(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return -1;
}

int dfs(int x, int y, int a, int b, int c, int d) {
    if (x == H && y == W) return 0;
    if (visited[x][y][a][b][c][d]) return dp[x][y][a][b][c][d];
    visited[x][y][a][b][c][d] = true;
    int result = -1;
    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= H && ny >= 1 && ny <= W && grid[nx][ny] != '#') {
            int na = a, nb = b, nc = c, nd = d;
            int idx = get_index(grid[nx][ny]);
            if (idx >= 0 && idx < 26) {
                if (idx == 0 && a < 10) ++na;
                else if (idx == 1 && b < 10) ++nb;
                else if (idx == 2 && c < 10) ++nc;
                else if (idx == 3 && d < 10) ++nd;
            } else if (idx >= 26 && idx < 52) {
                idx -= 26;
                int placed = 0;
                if (idx == 0 && a > 0) --na, ++placed;
                else if (idx == 1 && b > 0) --nb, ++placed;
                else if (idx == 2 && c > 0) --nc, ++placed;
                else if (idx == 3 && d > 0) --nd, ++placed;
                int next_result = dfs(nx, ny, na, nb, nc, nd);
                if (next_result != -1) result = max(result, next_result + placed);
            } else {
                int next_result = dfs(nx, ny, na, nb, nc, nd);
                if (next_result != -1) result = max(result, next_result);
            }
        }
    }
    dp[x][y][a][b][c][d] = result;
    return result;
}

int main() {
    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> grid[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(visited, false, sizeof(visited));
        int result = dfs(1, 1, 0, 0, 0, 0);
        cout << result << endl;
    }
}