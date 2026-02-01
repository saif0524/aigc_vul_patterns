#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> points(n);
        for(auto &p : points){
            cin >> p.first >> p.second;
        }
        int ans = INT_MAX;
        bool possible = false;
        for(int i = 0; i < n; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) <= k){
                    count++;
                }
            }
            if(count > 1){
                ans = min(ans, n - count);
                possible = true;
            }
        }
        if(possible){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}