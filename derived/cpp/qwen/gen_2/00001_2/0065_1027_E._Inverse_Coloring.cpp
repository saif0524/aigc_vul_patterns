#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
const int MOD = 998244353;

int n, k;
int dp[N][2];

bool check(int a, int b) {
    int cnt = 0;
    while (a && b) {
        if ((a & 1) == (b & 1)) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
        a >>= 1; b >>= 1;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(n == 1 && k == 1){
        cout << 0;
        return 0;
    }
    int m = 1 << n;
    for(int i=0; i<m; i++) dp[i][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dp[j][i%2] == 0) continue;
            int last = i == 0 ? 0 : j;
            dp[j][i%2^1] = 0;
            for(int k=0; k<m; k++){
                if(check(j, k) && check(last, k)){
                    dp[j][i%2^1] = (dp[j][i%2^1] + dp[k][i%2]) % MOD;
                }
            }
        }
    }
    int res = 0;
    for(int i=0; i<m; i++){
        res = (res + dp[i][n%2^1]) % MOD;
    }
    cout << res;
    return 0;
}