#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> pos(n);
    for(int i=0;i<n;i++) pos[a[i]-1]=i;
    vector<bool> vis(n);
    int ans = 0;
    vector<vector<int>> cycles;
    for(int i=0;i<n;i++){
        if(vis[i] || pos[i]==i) continue;
        int j = i;
        vector<int> cycle;
        int len = 0;
        while(!vis[j]){
            vis[j] = true;
            cycle.push_back(j+1);
            j = pos[j];
            len++;
        }
        ans++;
        if(len > s){
            cout << "-1";
            return 0;
        }
        s -= len;
        cycles.push_back(cycle);
    }
    cout << ans << "\n";
    for(auto &c: cycles){
        cout << c.size() << "\n";
        for(auto x: c) cout << x << " ";
        cout << "\n";
    }
}