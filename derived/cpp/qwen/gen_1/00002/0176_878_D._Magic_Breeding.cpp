#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<long long>> creatures(k+1, vector<long long>(n));
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            cin >> creatures[i][j];
        }
    }
    int next = k+1;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            creatures[next] = creatures[x];
            for(int i=0;i<n;i++){
                creatures[next][i] = max(creatures[next][i], creatures[y][i]);
            }
            next++;
        }
        else if(t == 2){
            creatures[next] = creatures[x];
            for(int i=0;i<n;i++){
                creatures[next][i] = min(creatures[next][i], creatures[y][i]);
            }
            next++;
        }
        else{
            cout << creatures[x][y-1] << "\n";
        }
    }
}