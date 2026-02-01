#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = n;
    deque<int> dq;
    for(int i = 0; i < n; ++i){
        while(!dq.empty() && a[i] - dq.front() > K) dq.pop_front();
        if(dq.empty() || a[i] - dq.front() <= K){
            dq.push_back(a[i]);
            ans = min(ans, (int)dq.size());
        }else{
            dq.pop_front();
            dq.push_back(a[i]);
        }
    }
    cout << ans;
}