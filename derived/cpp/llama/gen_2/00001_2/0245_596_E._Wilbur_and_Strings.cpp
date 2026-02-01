#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int MAXM = 1000005;

int dx[10], dy[10];
int n, m, q;
int a[MAXN][MAXN];
string s[MAXM];

bool vis[MAXN][MAXN];

bool dfs(int x, int y, string &s, int idx) {
    if (idx == s.size()) return true;
    if (vis[x][y]) return false;
    vis[x][y] = true;
    int nx = x + dx[s[idx] - '0'];
    int ny = y + dy[s[idx] - '0'];
    if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
        if (a[nx][ny] == s[idx] - '0') {
            if (dfs(nx, ny, s, idx + 1)) return true;
        } else if (dfs(nx, ny, s, idx)) return true;
    }
    if (dfs(x, y, s, idx + 1)) return true;
    vis[x][y] = false;
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            scanf(" %c", &c);
            a[i][j] = c - '0';
        }
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d%d", &dx[i], &dy[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> s[i];
        bool ok = false;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                memset(vis, 0, sizeof(vis));
                if (dfs(j, k, s[i], 0)) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}