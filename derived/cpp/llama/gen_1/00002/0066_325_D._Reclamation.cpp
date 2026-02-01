#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_R = 3000;
const int MAX_C = 3000;

int r, c, n;
int x[MAX_R * MAX_C], y[MAX_R * MAX_C];
bool sea[MAX_R][MAX_C];

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> r >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }
}

bool exists_path(bool sea[3000][3000], int r, int c) {
    bool vis[MAX_R][MAX_C];
    memset(vis, false, sizeof(vis));

    bool dfs(int i, int j) {
        if (i == r - 1) return true;
        if (vis[i][j] || !sea[i][j]) return false;
        vis[i][j] = true;

        bool found = dfs(i - 1, j) || dfs(i + 1, j) || dfs(i, j - 1) || dfs(i, j + 1);
        if (j == 0) found = found || dfs(i, c - 1);
        if (j == c - 1) found = found || dfs(i, 0);

        return found;
    }

    for (int j = 0; j < c; j++) {
        if (dfs(0, j)) return true;
    }
    return false;
}

void solve() {
    int cnt = 0;
    memset(sea, true, sizeof(sea));

    for (int i = 0; i < n; i++) {
        if (exists_path(sea, r, c)) {
            sea[x[i]][y[i]] = false;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    init();
    input();
    solve();
    return 0;
}