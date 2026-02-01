#include <bits/stdc++.h>
using namespace std;

const int MXN = 105;
int n, m, k;
char grid[MXN][MXN][MXN];
int dx[] = {1, 0, 0}, dy[] = {0, 1, 0}, dz[] = {0, 0, 1};
bool vis[MXN][MXN][MXN];

void dfs(int x, int y, int z) {
    if (vis[x][y][z]) return;
    vis[x][y][z] = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && nz >= 1 && nz <= k && grid[nx][ny][nz] == '1')
            dfs(nx, ny, nz);
    }
}

int count_neighbors(int x, int y, int z) {
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && nz >= 1 && nz <= k && grid[nx][ny][nz] == '1')
            cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;l<=k;l++){
                cin >> grid[i][j][l];
            }
        }
        if(i<n) cin.ignore();
    }
    int critical = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;l<=k;l++){
                if(grid[i][j][l] == '1' && count_neighbors(i, j, l) > 1){
                    memset(vis, 0, sizeof(vis));
                    dfs(1, 1, 1);
                    if(!vis[i][j][l]){
                        critical++;
                    }
                }
            }
        }
    }
    cout << critical;
}