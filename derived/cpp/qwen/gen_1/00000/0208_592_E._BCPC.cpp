#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vector<pair<ll, ll>> speeds(n);
    for(auto &s : speeds) cin >> s.first >> s.second;
    for(auto &s : speeds) s.first -= c, s.second -= d;
    auto compare = [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return a.first * b.second > a.second * b.first;
    };
    sort(speeds.begin(), speeds.end(), compare);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(speeds[i].first * speeds[j].second <= speeds[i].second * speeds[j].first) continue;
            int pos = upper_bound(speeds.begin() + j + 1, speeds.end(), speeds[i], compare) - speeds.begin();
            if(pos > j) ans += (pos - j - 1);
        }
    }
    cout << ans;
}