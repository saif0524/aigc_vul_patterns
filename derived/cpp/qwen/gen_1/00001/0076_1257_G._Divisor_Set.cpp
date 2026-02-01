#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p) cin >> i;
    
    map<int, int> freq;
    for (int i : p) freq[i]++;
    
    int max_pow = 0;
    for (auto &[_, cnt] : freq) {
        max_pow = max(max_pow, cnt);
    }
    
    long long ans = 1;
    for (int i = 0; i < max_pow; i++) {
        ans = (ans * 2) % MOD;
    }
    ans = (ans + MOD - 1) % MOD;
    
    cout << ans;
}