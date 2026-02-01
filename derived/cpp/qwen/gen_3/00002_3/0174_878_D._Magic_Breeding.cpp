#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> creatures(k+1, vector<int>(n));
    for(int i = 1; i <= k; ++i){
        for(int j = 0; j < n; ++j){
            cin >> creatures[i][j];
        }
    }
    int next_creature = k+1;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            creatures.push_back(vector<int>(n));
            for(int j = 0; j < n; ++j){
                creatures[next_creature][j] = max(creatures[x][j], creatures[y][j]);
            }
            next_creature++;
        }
        else if(t == 2){
            creatures.push_back(vector<int>(n));
            for(int j = 0; j < n; ++j){
                creatures[next_creature][j] = min(creatures[x][j], creatures[y][j]);
            }
            next_creature++;
        }
        else{
            cout << creatures[x][y-1] << "\n";
        }
    }
}