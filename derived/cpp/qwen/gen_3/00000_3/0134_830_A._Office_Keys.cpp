#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    multiset<int> keys(b.begin(), b.end());
    int ans = 0;
    for(auto x : a){
        auto it = keys.lower_bound(x);
        if(it == keys.end() || (it != keys.begin() && abs(*prev(it) - x) < abs(*it - x))){
            it = prev(it);
        }
        ans = max(ans, abs(x - *it) + abs(p - *it));
        keys.erase(it);
    }
    cout << ans;
}