#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int best = 1e9+7;
        int loc = a[i];
        int idx = lower_bound(b.begin(), b.end(), loc) - b.begin();
        if(idx < k){
            best = min(best, abs(loc-b[idx])+abs(p-b[idx]));
        }
        if(idx > 0){
            best = min(best, abs(loc-b[idx-1])+abs(p-b[idx-1]));
        }
        pq.push(best);
    }
    int ans = 0;
    while(n--){
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout << ans;
}