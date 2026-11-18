#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<vector<int>> subarrays(m, vector<int>(2));
    for(auto &v : subarrays){
        cin >> v[0] >> v[1];
        v[0]--; v[1]--;
    }
    int max_happiness = 0;
    for(int mask = 0; mask < (1<<m); ++mask){
        vector<int> cnt(n, 0);
        for(int i = 0; i < m; ++i){
            if(mask & (1<<i)){
                for(int j = subarrays[i][0]; j <= subarrays[i][1]; ++j){
                    cnt[j]++;
                }
            }
        }
        int happiness = 0;
        for(int i = 0; i < n; ++i){
            happiness += a[i] * cnt[i];
        }
        max_happiness = max(max_happiness, happiness);
    }
    cout << max_happiness;
}