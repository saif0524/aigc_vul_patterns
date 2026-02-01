#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for(int i=0; i<H; i++) cin >> s[i];
    
    vector<vector<int>> seen(H, vector<int>(W, 0));
    queue<pair<int, int>> q;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(s[i][j] == '#' && !seen[i][j]){
                q.push({i, j});
                seen[i][j] = 1;
                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();
                    if(x-1 >= 0 && s[x-1][y] == '#' && !seen[x-1][y]){
                        q.push({x-1, y});
                        seen[x-1][y] = 1;
                    }
                    if(x+1 < H && s[x+1][y] == '#' && !seen[x+1][y]){
                        q.push({x+1, y});
                        seen[x+1][y] = 1;
                    }
                    if(y-1 >= 0 && s[x][y-1] == '#' && !seen[x][y-1]){
                        q.push({x, y-1});
                        seen[x][y-1] = 1;
                    }
                    if(y+1 < W && s[x][y+1] == '#' && !seen[x][y+1]){
                        q.push({x, y+1});
                        seen[x][y+1] = 1;
                    }
                }
            }
        }
    }
    
    bool possible = true;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(s[i][j] == '#' && !seen[i][j]){
                possible = false;
                break;
            }
        }
        if(!possible) break;
    }
    
    cout << (possible ? "Yes" : "No");
}