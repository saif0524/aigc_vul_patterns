#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++) pos[a[i]].push_back(i);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(pos[i].size() < 2) continue;
        int f = 1;
        deque<int> q;
        for(int idx: pos[i]){
            while(!q.empty() && q.front() < idx - f) q.pop_front();
            if(!q.empty()){
                ans = max(ans, idx - q.front() + f);
            }
            while(!q.empty() && idx - q.back() <= f) q.pop_back();
            q.push_back(idx);
            if(q.size() >= 2) ans = max(ans, f*2);
            if(q.size() >= 3) q.pop_front();
            f++;
        }
    }
    cout << ans;
}