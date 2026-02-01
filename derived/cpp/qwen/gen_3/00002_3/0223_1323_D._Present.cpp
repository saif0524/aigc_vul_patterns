#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int sum = 0;
    for(auto x: a) sum ^= x;
    int ans = 0;
    for(auto x: a) ans ^= (sum ^ x);
    cout << ans;
}