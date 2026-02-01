#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(1 << H, vector<int>(W, 0));
    for(int mask = 0; mask < (1 << H); mask++){
        for(int j = 0; j < W; j++){
            int cnt = __builtin_popcount(mask);
            for(int mask2 = 0; mask2 < (1 << H); mask2++){
                if(__builtin_popcount(mask2) != cnt -1 || (mask & mask2) != mask2){
                    continue;
                }
                int val = 0;
                for(int i = 0; i < H; i++){
                    if(mask2 & (1 << i)){
                        val += a[i][j];
                    }
                }
                dp[mask][j] = max(dp[mask][j], dp[mask2][j-1] + val);
            }
            if(cnt ==1){
                for(int i = 0; i < H; i++){
                    if(mask & (1 << i)){
                        dp[mask][j] = max(dp[mask][j], a[i][j]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < W; j++){
        for(int mask = 0; mask < (1 << H); mask++){
            ans = max(ans, dp[mask][j]);
        }
    }
    cout << ans << endl;
}