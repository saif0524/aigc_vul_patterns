#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> points(n);
        for(auto &p : points) cin >> p.first >> p.second;
        int ans = n;
        bool possible = false;
        for(int i=0; i<n; ++i){
            int cnt = 0;
            for(int j=0; j<n; ++j){
                if(abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) <= k) cnt++;
            }
            ans = min(ans, n - cnt);
            if(cnt == n) possible = true;
        }
        if(possible) cout << ans << "\n";
        else cout << "-1\n";
    }
}