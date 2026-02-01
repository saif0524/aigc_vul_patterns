#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n), t(n);
    for(auto &x: a) cin >> x;
    for(auto &x: t) cin >> x;
    sort(a.begin(), a.end());
    sort(t.begin(), t.end(), greater<long long>());
    long long total_time = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]) continue;
        long long needed = a[i-1] + 1 - a[i];
        a[i] += needed;
        total_time += needed * t[i];
    }
    cout << total_time;
}