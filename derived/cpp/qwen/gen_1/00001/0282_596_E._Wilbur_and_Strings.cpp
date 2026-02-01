#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    vector<pair<int,int>> moves(10);
    for(int i=0;i<10;i++){
        cin >> moves[i].first >> moves[i].second;
    }
    vector<unordered_map<long long, unordered_set<long long>>> reachable(10);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int d = grid[i][j] - '0';
            queue<pair<int,int>> bfs;
            bfs.push({i, j});
            reachable[d][i*m+j].insert(i*m+j);
            while(!bfs.empty()){
                auto [x, y] = bfs.front();
                bfs.pop();
                int nx = x + moves[d].first;
                int ny = y + moves[d].second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int nd = grid[nx][ny] - '0';
                    if(reachable[d].find(nx*m+ny) == reachable[d].end() || reachable[d][nx*m+ny].find(i*m+j) == reachable[d][nx*m+ny].end()){
                        reachable[d][nx*m+ny].insert(i*m+j);
                        bfs.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int qq=0;qq<q;qq++){
        string s;
        cin >> s;
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool ok = true;
                int x = i, y = j;
                for(char c : s){
                    int d = c - '0';
                    if(reachable[d].find(x*m+y) == reachable[d].end()){
                        ok = false;
                        break;
                    }
                    bool moved = false;
                    for(auto pos : reachable[d][x*m+y]){
                        int nx = pos / m, ny = pos % m;
                        if(grid[nx][ny] - '0' == d){
                            x = nx;
                            y = ny;
                            moved = true;
                            break;
                        }
                    }
                    if(!moved){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}