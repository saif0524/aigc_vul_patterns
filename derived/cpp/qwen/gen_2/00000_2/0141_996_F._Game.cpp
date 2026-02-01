#include <bits/stdc++.h>
using namespace std;

long long dp[1<<18];

double evaluate(int n, long long dp[]) {
    double res = 0;
    for (int i = 0; i < (1 << n); ++i) {
        res += dp[i];
    }
    return res / (1 << n);
}

void update_dp(int n, int pos, long long val, long long dp[]) {
    for (int mask = 0; mask < (1 << n); ++mask) {
        if ((mask & (1 << pos)) == 0) {
            dp[mask] -= val;
            dp[mask | (1 << pos)] += val;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<long long> f(1<<n);
    for(auto &i: f) cin >> i;
    copy(f.begin(), f.end(), dp);
    for(int i=0;i<n;++i){
        for(int mask = (1<<n)-1;mask>=0;--mask){
            if(mask & (1<<i)){
                dp[mask] -= f[mask];
                dp[mask^(1<<i)] += f[mask];
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << evaluate(n, dp) << "\n";
    for(int i=0;i<r;++i){
        int z, g;
        cin >> z >> g;
        long long diff = g - f[z];
        f[z] = g;
        update_dp(n, z, diff, dp);
        cout << evaluate(n, dp) << "\n";
    }
}