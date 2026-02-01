#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for(auto &row : grid) cin >> row;
    vector<pair<int,int>> spiders;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j] != '.'){
                char dir = grid[i][j];
                grid[i][j] = '.';
                if(dir == 'L') spiders.push_back({i, j});
                else if(dir == 'R') spiders.push_back({i, -j});
                else if(dir == 'U') spiders.push_back({j, -i});
                else spiders.push_back({-j, i});
            }
        }
    }
    vector<vector<int>> counts(n, vector<int>(m));
    for(auto [dx, dy] : spiders){
        int x = 0, y = dx;
        while(x >= 0 && x < n && y >= 0 && y < m){
            counts[x][y]++;
            x++, y += dy;
        }
    }
    for(int j=0; j<m; ++j) cout << counts[0][j] << (j==m-1?'\n':' ');
}