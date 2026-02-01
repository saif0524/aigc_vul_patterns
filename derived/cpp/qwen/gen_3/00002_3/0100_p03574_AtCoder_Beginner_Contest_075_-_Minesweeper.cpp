#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for(auto &row: grid) cin >> row;
    
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(grid[i][j] == '.'){
                int bomb_count = 0;
                for(int k = 0; k < 8; ++k){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == '#'){
                        bomb_count++;
                    }
                }
                grid[i][j] = '0' + bomb_count;
            }
        }
    }
    
    for(const auto &row: grid){
        cout << row << "\n";
    }
    return 0;
}