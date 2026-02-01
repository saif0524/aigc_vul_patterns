#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,long long>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        multiset<long long> ms;
        int have = 0;
        for(int i=0;i<n;i++){
            while(have <= v[i].first && !ms.empty()){
                have++;
                ans += *ms.begin();
                ms.erase(ms.begin());
            }
            if(have > v[i].first){
                ms.insert(v[i].second);
            }
        }
        while(have < n && !ms.empty()){
            have++;
            ans += *ms.begin();
            ms.erase(ms.begin());
        }
        cout << ans << "\n";
    }
}