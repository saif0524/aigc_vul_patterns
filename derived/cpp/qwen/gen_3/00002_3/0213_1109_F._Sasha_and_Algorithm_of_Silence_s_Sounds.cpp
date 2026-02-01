#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m;
int f[MAXN][MAXN];
pair<int, int> pos[MAXN * MAXN + 1];
int dsu[MAXN * MAXN + 1];

int find(int x) {
    if (dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}

void join(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        dsu[rx] = ry;
    }
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y, int l, int r) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (f[x][y] < l || f[x][y] > r) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> f[i][j];
            pos[f[i][j]] = {i, j};
        }
    }
    long long ans = 0;
    for(int l = 1; l <= n * m; l++){
        for(int i = 1; i <= n * m; i++) dsu[i] = i;
        int cnt = 0;
        for(int r = l; r <= n * m; r++){
            int x = pos[r].first;
            int y = pos[r].second;
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(valid(nx, ny, l, r)){
                    int u = f[x][y];
                    int v = f[nx][ny];
                    if(find(u) != find(v)){
                        join(u, v);
                        cnt++;
                    }
                }
            }
            int cells = r - l + 1;
            if(cells - cnt == 1) ans++;
            else if(cells - cnt < 1) break;
        }
    }
    cout << ans;
}