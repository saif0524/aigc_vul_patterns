#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for(int i=0;i<H;i++){
        cin >> grid[i];
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(grid[i][j] == '#'){
                bool valid = false;
                if(i+1 < H && grid[i+1][j] == '#') valid = true;
                if(i-1 >= 0 && grid[i-1][j] == '#') valid = true;
                if(j+1 < W && grid[i][j+1] == '#') valid = true;
                if(j-1 >= 0 && grid[i][j-1] == '#') valid = true;
                if(!valid){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}