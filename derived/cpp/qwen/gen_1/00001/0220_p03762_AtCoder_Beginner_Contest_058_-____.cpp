#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> x(n), y(m);
    for(auto &i: x) cin >> i;
    for(auto &i: y) cin >> i;
    
    long long sumX = 0, sumY = 0;
    for(int i=1; i<n; ++i){
        sumX += (x[i] - x[i-1]) * 1LL * (n-i);
        sumX %= MOD;
    }
    for(int i=1; i<m; ++i){
        sumY += (y[i] - y[i-1]) * 1LL * (m-i);
        sumY %= MOD;
    }
    
    long long result = (sumX * sumY) % MOD;
    cout << result;
}