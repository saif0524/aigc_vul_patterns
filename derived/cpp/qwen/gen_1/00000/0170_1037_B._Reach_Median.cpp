#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = abs(a[n/2] - s);
    cout << ans;
}