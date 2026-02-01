#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 55;

char grid[MAX_N][MAX_N];
bool row_used[MAX_N], col_used[MAX_N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", grid[i] + 1);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#') {
                if (row_used[i] && col_used[j]) {
                    ok = false;
                    break;
                }
                if (!row_used[i] && !col_used[j]) {
                    row_used[i] = true;
                    col_used[j] = true;
                }
            }
        }
        if (!ok) break;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#' && !row_used[i] && !col_used[j]) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}