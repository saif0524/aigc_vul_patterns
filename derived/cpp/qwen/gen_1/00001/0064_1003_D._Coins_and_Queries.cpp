#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> freq(31, 0);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int p = 0;
        while((1<<p) < x) p++;
        freq[p]++;
    }
    vector<int> dp(1<<16, -1);
    dp[0] = 0;
    for(int mask=0; mask<(1<<15); mask++){
        if(dp[mask] != -1){
            for(int i=0; i<15; i++){
                if(freq[i] > 0 && (mask & (1<<i)) == 0){
                    int nmask = mask | (1<<i);
                    if(dp[nmask] == -1 || dp[nmask] > dp[mask] + 1){
                        dp[nmask] = dp[mask] + 1;
                    }
                }
            }
        }
    }
    while(q--){
        int b;
        cin >> b;
        vector<int> used(15, 0);
        int sum = 0;
        for(int i=0; i<15; i++){
            if(b & (1<<i)){
                sum += min(freq[i], 1);
            }
        }
        int remaining = b;
        int needed = 0;
        for(int i=14; i>=0; i--){
            if(remaining & (1<<i)){
                if(dp[remaining] != -1){
                    needed = dp[remaining];
                    break;
                }
            }
        }
        if(needed == -1 || sum + needed > freq[i]){
            cout << -1 << "\n";
        } else {
            cout << sum + needed << "\n";
        }
    }
}