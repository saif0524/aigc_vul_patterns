#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MASK = (1 << 7) - 1;

int n, m, k, a[MAXN][MAXN], p[7][2];
int dist[MAXN][MAXN];
int memo[1 << 7][MAXN][MAXN];

int get_dist(int x1, int y1, int x2, int y2) {
    if (dist[x1][y1] > 0) return 1e9;
    dist[x1][y1] = 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[nx][ny] > 0) continue;
                dist[nx][ny] = dist[x][y] + a[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    int d = dist[x2][y2];
    memset(dist, 0, sizeof(dist));
    return d;
}

int dp(int mask, int x, int y) {
    if (memo[mask][x][y] != -1) return memo[mask][x][y];
    if (__builtin_popcount(mask) == k) return 0;
    int ans = 1e9;
    for (int i = 0; i < k; i++) {
        if ((mask >> i) & 1) continue;
        int d = get_dist(x, y, p[i][0], p[i][1]);
        if (d == 1e9) continue;
        ans = min(ans, d + dp(mask | (1 << i), p[i][0], p[i][1]));
    }
    return memo[mask][x][y] = ans;
}

void get_path(int mask, int x, int y, vector<pair<int, int>>& path) {
    if (__builtin_popcount(mask) == k) return;
    int ans = dp(mask, x, y);
    for (int i = 0; i < k; i++) {
        if ((mask >> i) & 1) continue;
        int d = get_dist(x, y, p[i][0], p[i][1]);
        if (d == 1e9) continue;
        if (ans == d + dp(mask | (1 << i), p[i][0], p[i][1])) {
            for (int xx = x, yy = y; xx != p[i][0] || yy != p[i][1]; ) {
                path.push_back({xx, yy});
                if (xx < p[i][0]) xx++;
                else if (xx > p[i][0]) xx--;
                else if (yy < p[i][1]) yy++;
                else if (yy > p[i][1]) yy--;
            }
            path.push_back({p[i][0], p[i][1]});
            get_path(mask | (1 << i), p[i][0], p[i][1], path);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> p[i][0] >> p[i][1];
        p[i][0]--;
        p[i][1]--;
    }
    memset(memo, -1, sizeof(memo));
    int ans = 1e9;
    pair<int, int> start;
    for (int i = 0; i < k; i++) {
        int d = dp(1 << i, p[i][0], p[i][1]);
        if (d < ans) {
            ans = d;
            start = {p[i][0], p[i][1]};
        }
    }
    vector<pair<int, int>> path;
    get_path(1 << 0, start.first, start.second, path);
    cout << ans << '\n';
    vector<vector<char>> g(n, vector<char>(m, '.'));
    for (auto [x, y] : path) {
        g[x][y] = 'X';
    }
    for (auto row : g) {
        for (char c : row) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}