#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

ll n, k, m;
vector<pair<int, int>> events[MAXN];
ll dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i=0; i<m; i++){
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        events[l-1].emplace_back(c, -p);
        events[r].emplace_back(c, p);
    }
    for(int i=0; i<n; i++){
        ll avail = 0;
        for(auto &e : events[i]){
            if(e.second < 0){
                avail += e.first;
            }
            else{
                avail -= e.first;
            }
        }
        dp[i] = avail * (-events[i][0].second);
        if(i > 0){
            dp[i] = min(dp[i], dp[i-1] + max(0LL, k - avail) * (-events[i][0].second));
        }
    }
    cout << dp[n-1] << "\n";
}