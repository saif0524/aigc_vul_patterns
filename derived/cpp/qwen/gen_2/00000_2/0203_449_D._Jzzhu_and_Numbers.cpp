#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int MAX_MASK = (1 << 20) + 5;

int n;
int a[MAXN];
int dp[MAX_MASK];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int mask=1;mask<MAX_MASK;mask++){
        for(int i=0;i<n;i++){
            if((mask & a[i]) == 0){
                dp[mask] = (dp[mask] + dp[mask ^ a[i]]) % MOD;
            }
        }
    }
    long long ans = 0;
    for(int mask=1;mask<MAX_MASK;mask++){
        ans = (ans + dp[mask]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}