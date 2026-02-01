#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        cnt[p]++;
    }
    long long ans = 1;
    for(auto &[p, c] : cnt){
        ans = (ans * (c + 1)) % MOD;
    }
    ans = (ans + MOD - 1) % MOD;
    cout << ans;
}