#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
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
    vector<vector<vector<bool>>> reachable(10, vector<vector<bool>>(n, vector<bool>(m, false)));
    for(int d=0;d<10;d++){
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]-'0'==d){
                    q.push({i,j});
                    reachable[d][i][j] = true;
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            int nx = x + moves[d].first;
            int ny = y + moves[d].second;
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(!reachable[d][nx][ny]){
                    reachable[d][nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    while(q--){
        string s;
        cin >> s;
        bool possible = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool valid = true;
                int x = i, y = j;
                for(char c : s){
                    int d = c-'0';
                    if(!reachable[d][x][y]){
                        valid = false;
                        break;
                    }
                    x += moves[d].first;
                    y += moves[d].second;
                    if(x<0|| x>=n || y<0 || y>=m){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    possible = true;
                    break;
                }
            }
            if(possible) break;
        }
        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
}