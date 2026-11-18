#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    long long result = 0;
    long long sign = 1;
    for(int i=0;i<n;i++){
        result = (result + sign * a[i]) % MOD;
        sign *= -1;
    }
    if(result < 0) result += MOD;
    cout << result;
    return 0;
}