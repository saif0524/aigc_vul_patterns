#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXN = 100005;
const int MAXV = 201;

ll dp[MAXN][MAXV];
int a[MAXN];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int first = a[1] == -1 ? 1 : a[1], last = a[n] == -1 ? 200 : a[n];
    for(int i=first;i<=last;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        int val = a[i];
        if(val != -1){
            for(int j=max(1,val-1);j<=min(MAXV-1,val+1);j++){
                (dp[i][val] += dp[i-1][j]) %= MOD;
            }
        }
        else{
            for(int j=1;j<=MAXV;j++){
                dp[i][j] = 0;
                for(int k=max(1,j-1);k<=min(MAXV-1,j+1);k++){
                    (dp[i][j] += dp[i-1][k]) %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    int final_val = a[n] == -1 ? 200 : a[n];
    for(int i=max(1,final_val-1);i<=min(MAXV-1,final_val+1);i++){
        (ans += dp[n][i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}