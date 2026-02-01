#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0);
    int res = 0;
    for(auto &x: a) res ^= (sum - x);
    cout << res;
}