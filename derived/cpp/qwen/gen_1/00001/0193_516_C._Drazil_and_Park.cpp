#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for(auto &x: d) cin >> x;
    vector<ll> h(n);
    for(auto &x: h) cin >> x;
    vector<ll> pre(n+1, 0);
    for(int i=0; i<n; ++i){
        pre[i+1] = pre[i] + d[i];
    }
    auto dist = [&](int a, int b){
        if(a > b) swap(a, b);
        return min(pre[b] - pre[a], pre[n] - (pre[b] - pre[a]));
    };
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        ll ans = 0;
        for(int c=0; c<n; ++c){
            if(c == a || c == b) continue;
            for(int d=c+1; d<n; ++d){
                if(d == a || d == b) continue;
                ll energy = 2*(h[c] + h[d]) + dist(c, d);
                ans = max(ans, energy);
            }
        }
        cout << ans << "\n";
    }
}