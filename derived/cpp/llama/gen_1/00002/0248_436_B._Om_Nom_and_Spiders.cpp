#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;
int n, m, k, ans[maxn];
char s[maxn][maxn];

struct spider {
    int x, y, dir;
};

vector<spider> spiders;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != '.') {
                spider sp;
                sp.x = i;
                sp.y = j;
                if (s[i][j] == 'U') sp.dir = 0;
                if (s[i][j] == 'D') sp.dir = 1;
                if (s[i][j] == 'L') sp.dir = 2;
                if (s[i][j] == 'R') sp.dir = 3;
                spiders.push_back(sp);
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vector<vector<int>> seen(n, vector<int>(m, 0));

    for (int t = 0; t < n; ++t) {
        for (auto& sp : spiders) {
            int x = sp.x + dx[sp.dir];
            int y = sp.y + dy[sp.dir];
            if (0 <= x && x < n && 0 <= y && y < m) {
                sp.x = x;
                sp.y = y;
                seen[sp.x][sp.y] = 1;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (seen[t][j] == 1) ans[j]++;
        }

        for (int j = 0; j < m; ++j) {
            seen[t][j] = 0;
        }
    }

    for (int j = 0; j < m; ++j) {
        printf("%d ", ans[j]);
    }
    printf("\n");

    return 0;
}