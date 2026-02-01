#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for(auto &p : intervals) cin >> p.first >> p.second;
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    vector<int> pre(k+1, 1);
    for(int i=1; i<=k; i++) pre[i] = (1LL * pre[i-1] * (n-i+1)) % MOD * modPow(i, MOD-2) % MOD;
    int ans = 0;
    set<int> active;
    for(int i=0; i<n; i++){
        while(!active.empty() && *active.begin() < intervals[i].first){
            int l = *active.begin();
            active.erase(active.begin());
            int cnt = active.size();
            if(cnt >= k-1){
                int ways = pre[cnt];
                ans = (ans + ways) % MOD;
            }
        }
        active.insert(intervals[i].second);
        int cnt = active.size();
        if(cnt >= k){
            int ways = pre[cnt];
            ans = (ans + ways) % MOD;
        }
    }
    cout << ans;
}

int modPow(int base, int exp){
    if(exp == 0) return 1;
    long long half = modPow(base, exp/2);
    long long ret = half * half % MOD;
    if(exp % 2 == 1) ret = ret * base % MOD;
    return ret;
}