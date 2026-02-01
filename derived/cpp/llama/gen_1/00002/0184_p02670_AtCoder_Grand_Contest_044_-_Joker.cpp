#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX_N = 505;

int n;
int p[MAX_N * MAX_N];
bool vis[MAX_N][MAX_N];

int get_x(int x) {
    return (x - 1) / n;
}

int get_y(int x) {
    return (x - 1) % n;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ans;

void solve(int x, int y, int dir) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (vis[x][y]) {
        ans++;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (i == dir) solve(nx, ny, i);
        else solve(nx, ny, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> p[i];
        vis[get_x(p[i])][get_y(p[i])] = true;
    }
    ans = 0;
    for (int i = n * n - 1; i >= 0; i--) {
        int x = get_x(p[i]);
        int y = get_y(p[i]);
        vis[x][y] = false;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            solve(nx, ny, j);
        }
    }

    cout << ans << endl;
    return 0;
}