#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    long long p;
    cin >> n >> k >> p;
    vector<long long> a(n), b(k);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    multiset<long long> s(b.begin(), b.end());
    for(auto x: a){
        auto it = s.lower_bound(x);
        if(it == s.end() || (*it > p && it != s.begin())){
            if(it != s.begin()) it--;
        }
        long long key = *it;
        s.erase(it);
        long long time = min(abs(key - x) + abs(p - key), abs(key - p) + abs(p - x));
        ans = max(ans, time);
    }
    cout << ans;
}