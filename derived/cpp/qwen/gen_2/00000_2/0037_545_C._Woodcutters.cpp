#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> trees(n);
    for(auto &t : trees){
        cin >> t.first >> t.second;
    }
    set<long long> s;
    s.insert(-1e18);
    s.insert(1e18);
    int ans = 0;
    for(auto &[x, h] : trees){
        auto it = s.lower_bound(x);
        long long r = *it;
        it--;
        long long l = *it;
        if(x - h > l && x + h < r){
            ans++;
            s.insert(x - h);
            s.insert(x + h);
        }
    }
    cout << ans;
}