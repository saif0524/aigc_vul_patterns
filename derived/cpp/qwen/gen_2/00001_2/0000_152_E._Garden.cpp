#include <bits/stdc++.h>
using namespace std;

const int N = 110, K = 10;
int n, m, k;
int a[N][N];
vector<pair<int, int>> important;
int dp[1<<K];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        important.push_back({x, y});
    }
    
    vector<vector<vector<pair<int, int>>>> paths(1<<k);
    for(int mask=0;mask<(1<<k);mask++){
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if((mask& (1<<i)) && (mask&(1<<j))){
                    queue<pair<int, int>> q;
                    vector<vector<bool>> seen(n, vector<bool>(m, false));
                    q.push(important[i]);
                    seen[important[i].first][important[i].second] = true;
                    while(!q.empty()){
                        auto [cx, cy] = q.front(); q.pop();
                        if(cx == important[j].first && cy == important[j].second){
                            paths[mask].push_back({important[i], important[j]});
                            break;
                        }
                        int dx[] = {0, 0, 1, -1};
                        int dy[] = {1, -1, 0, 0};
                        for(int dir=0;dir<4;dir++){
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];
                            if(valid(nx, ny) && !seen[nx][ny]){
                                q.push({nx, ny});
                                seen[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int mask=0;mask<(1<<k);mask++){
        dp[mask] = 1e9;
    }
    dp[0] = 0;
    for(int mask=1;mask<(1<<k);mask++){
        for(auto p : paths[mask]){
            int new_mask = mask ^ (1<<(p.first == important[0] ? 0 : 1));
            dp[mask] = min(dp[mask], dp[new_mask] + a[p.first.first][p.first.second] + a[p.second.first][p.second.second]);
        }
    }
    
    int final_mask = (1<<k) - 1;
    vector<pair<int, int>> path;
    set<pair<int, int>> used;
    for(int mask=final_mask;mask>0;mask){
        for(auto p : paths[mask]){
            int new_mask = mask ^ (1<<(p.first == important[0] ? 0 : 1));
            if(dp[mask] == dp[new_mask] + a[p.first.first][p.first.second] + a[p.second.first][p.second.second]){
                path.push_back(p.first);
                path.push_back(p.second);
                used.insert(p.first);
                used.insert(p.second);
                mask = new_mask;
                break;
            }
        }
    }
    
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(auto p : used){
        grid[p.first][p.second] = 1;
    }
    for(auto p : path){
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        q.push(p);
        set<pair<int, int>> visited;
        visited.insert(p);
        while(!q.empty()){
            auto [cx, cy] = q.front(); q.pop();
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            for(int dir=0;dir<4;dir++){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(valid(nx, ny) && !visited.count({nx, ny}) && !used.count({nx, ny})){
                    q.push({nx, ny});
                    visited.insert({nx, ny});
                    grid[nx][ny] = 1;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans += grid[i][j] * a[i][j];
        }
    }
    
    cout << ans << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << (grid[i][j] ? 'X' : '.');
        }
        cout << "\n";
    }
}