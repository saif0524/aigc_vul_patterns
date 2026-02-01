#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    unordered_map<ll, int> xor_count;
    xor_count[0] = 1;
    ll current_xor = 0;
    ll result = 0;
    for(int i = 0; i < n; ++i){
        current_xor ^= a[i];
        result += xor_count[current_xor];
        xor_count[current_xor]++;
    }
    cout << result;
}