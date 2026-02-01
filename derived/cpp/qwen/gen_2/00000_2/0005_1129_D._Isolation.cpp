#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a){
        cin >> x;
    }
    vector<int> dp(n+1, 0);
    vector<int> freq(n+1, 0);
    dp[0] = 1;
    int unique = 0;
    int exact_once = 0;
    for(int i = 1; i <= n; ++i){
        int x = a[i-1];
        if(freq[x] == 1){
            --exact_once;
        }
        ++freq[x];
        if(freq[x] == 1){
            ++exact_once;
        }
        if(freq[x] == 2){
            --exact_once;
        }
        if(exact_once <= k){
            dp[i] = dp[i-1];
            if(i > 1){
                if(exact_once - (freq[a[i-2]] == 1) + (freq[a[i-2]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-2]) % MOD;
                }
            }
            if(i > 2){
                if(exact_once - (freq[a[i-3]] == 1) + (freq[a[i-3]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-3]) % MOD;
                }
            }
            if(i > 3){
                if(exact_once - (freq[a[i-4]] == 1) + (freq[a[i-4]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-4]) % MOD;
                }
            }
            if(i > 4){
                if(exact_once - (freq[a[i-5]] == 1) + (freq[a[i-5]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-5]) % MOD;
                }
            }
            if(i > 5){
                if(exact_once - (freq[a[i-6]] == 1) + (freq[a[i-6]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-6]) % MOD;
                }
            }
            if(i > 6){
                if(exact_once - (freq[a[i-7]] == 1) + (freq[a[i-7]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-7]) % MOD;
                }
            }
            if(i > 7){
                if(exact_once - (freq[a[i-8]] == 1) + (freq[a[i-8]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-8]) % MOD;
                }
            }
            if(i > 8){
                if(exact_once - (freq[a[i-9]] == 1) + (freq[a[i-9]] == 0) <= k){
                    dp[i] = (dp[i] + dp[i-9]) % MOD;
                }
            }
        }
    }
    cout << dp[n] << "\n";
}