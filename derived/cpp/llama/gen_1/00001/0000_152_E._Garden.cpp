#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, k;
int a[105][105];
int imp[7][2];
int memo[105][105][1 << 7];
int ans = INT_MAX;
char res[105][105];

int dp(int x, int y, int mask) {
    if (memo[x][y][mask] != -1) return memo[x][y][mask];
    if (__builtin_popcount(mask) == k) return a[x][y];
    int &ret = memo[x][y][mask];
    ret = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        int nmask = mask;
        for (int j = 0; j < k; j++) {
            if (imp[j][0] == nx && imp[j][1] == ny) nmask |= (1 << j);
        }
        ret = min(ret, a[x][y] + dp(nx, ny, nmask));
    }
    return ret;
}

void path(int x, int y, int mask) {
    if (__builtin_popcount(mask) == k) {
        res[x][y] = 'X';
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        int nmask = mask;
        for (int j = 0; j < k; j++) {
            if (imp[j][0] == nx && imp[j][1] == ny) nmask |= (1 << j);
        }
        if (dp(nx, ny, nmask) == dp(x, y, mask) - a[x][y]) {
            res[x][y] = 'X';
            path(nx, ny, nmask);
            return;
        }
    }
}

int main() {
    memset(memo, -1, sizeof memo);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &imp[i][0], &imp[i][1]);
    }
    for (int i = 0; i < k; i++) {
        int cur = dp(imp[i][0], imp[i][1], 1 << i);
        if (cur < ans) {
            ans = cur;
            memset(res, '.', sizeof res);
            path(imp[i][0], imp[i][1], 1 << i);
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}