#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m));
    for(auto& v: g) for(auto& x: v) cin >> x;
    
    vector<pair<int, int>> pts(k);
    for(auto& [x, y]: pts) cin >> x >> y, --x, --y;
    
    vector<vector<int>> dp(1<<k, vector<int>(k, inf));
    vector<vector<int>> pre(1<<k, vector<int>(k, -1));
    for(int i=0; i<k; ++i) dp[1<<i][i] = g[pts[i].first][pts[i].second];
    
    auto inside = [&](int i, int j){
        return i>=0&&i<n&&j>=0&&j<m;
    };
    
    vector<vector<int>> dist(n, vector<int>(m));
    for(int msk=1; msk<(1<<k); ++msk){
        for(int v=0; v<k; ++v) if(msk&(1<<v)){
            queue<pair<int, int>> q;
            for(auto& x: dist) fill(x.begin(), x.end(), inf);
            dist[pts[v].first][pts[v].second] = 0;
            q.emplace(pts[v]);
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int d=0; d<4; ++d){
                    int nx = x+dx[d], ny = y+dy[d];
                    if(inside(nx, ny) && dist[nx][ny]==inf){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }
            for(int u=0; u<k; ++u) if(msk&(1<<u) && u!=v){
                int sm = 0;
                for(auto& x: dist) for(auto& y: x) if(y!=inf) sm += g[pts[u].first][pts[u].second];
                if(dp[msk-(1<<v)][u] + g[pts[v].first][pts[v].second] + sm < dp[msk][v]){
                    dp[msk][v] = dp[msk-(1<<v)][u] + g[pts[v].first][pts[v].second] + sm;
                    pre[msk][v] = u;
                }
            }
        }
    }
    
    int best = inf;
    int bstmask = -1;
    int bstend = -1;
    for(int i=0; i<k; ++i) if(best > dp[(1<<k)-1][i]){
        best = dp[(1<<k)-1][i];
        bstmask = (1<<k)-1;
        bstend = i;
    }
    
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    for(int i=0; i<k; ++i){
        ans[pts[i].first][pts[i].second] = 'X';
    }
    
    while(bstmask!=0){
        int prev = pre[bstmask][bstend];
        auto [curx, cury] = pts[bstend];
        queue<pair<int, int>> q;
        for(auto& x: dist) fill(x.begin(), x.end(), inf);
        dist[curx][cury] = 0;
        q.emplace(curx, cury);
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x==pts[prev].first && y==pts[prev].second) break;
            for(int d=0; d<4; ++d){
                int nx = x+dx[d], ny = y+dy[d];
                if(inside(nx, ny) && dist[nx][ny]==inf){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        auto [endx, endy] = pts[prev];
        for(; !(curx==endx && cury==endy);){
            ans[curx][cury] = 'X';
            int nd = -1;
            for(int d=0; d<4; ++d){
                int nx = curx + dx[d];
                int ny = cury + dy[d];
                if(inside(nx, ny) && dist[nx][ny] == dist[curx][cury] - 1){
                    nd = d;
                    break;
                }
            }
            curx += dx[nd];
            cury += dy[nd];
        }
        bstmask ^= (1<<bstend);
        bstend = prev;
    }
    
    cout << best << "\n";
    for(auto& row: ans){
        for(auto& x: row) cout << x;
        cout << "\n";
    }
}