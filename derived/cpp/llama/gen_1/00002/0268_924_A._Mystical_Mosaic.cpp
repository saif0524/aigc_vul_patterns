#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

char grid[MAXN][MAXN];
bool row[MAXN], col[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    bool ok = true;
    while (true) {
        int r = -1, c = -1;
        for (int i = 0; i < n; i++) {
            if (row[i]) {
                bool all = true;
                for (int j = 0; j < m; j++) {
                    if (col[j] && grid[i][j] == '.') {
                        all = false;
                        break;
                    }
                }
                if (all) {
                    r = i;
                    break;
                }
            }
        }
        if (r != -1) {
            for (int j = 0; j < m; j++) {
                if (col[j]) {
                    grid[r][j] = '.';
                }
            }
            row[r] = false;
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (col[j]) {
                bool all = true;
                for (int i = 0; i < n; i++) {
                    if (row[i] && grid[i][j] == '.') {
                        all = false;
                        break;
                    }
                }
                if (all) {
                    c = j;
                    break;
                }
            }
        }
        if (c != -1) {
            for (int i = 0; i < n; i++) {
                if (row[i]) {
                    grid[i][c] = '.';
                }
            }
            col[c] = false;
            continue;
        }
        break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }

    printf("%s\n", ok ? "Yes" : "No");
    return 0;
}