#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll,int>> events;
    for(int i=0;i<n;i++){
        ll l,r;
        cin >> l >> r;
        events.push_back({l,1});
        events.push_back({r+1,-1});
    }
    sort(events.begin(),events.end());
    vector<ll> cnt(n+1,0);
    int active=0;
    for(auto &e:events){
        cnt[active]+=(e.first-(active?events[i-1].first:0));
        active+=(e.second);
    }
    for(int i=1;i<=n;i++) cout << cnt[i] << (i==n?"\n":" ");
}