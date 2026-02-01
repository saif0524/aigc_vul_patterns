#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> grid;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || visited[x][y]) return;
    visited[x][y] = true;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    grid.resize(n);
    for (auto &row: grid) cin >> row;
    visited.resize(n, vector<bool>(m, false));
    dfs(0,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && visited[i][j] && k > 0){
                grid[i][j] = 'X';
                k--;
            }
        }
    }
    for(auto &row: grid) cout << row << "\n";
}