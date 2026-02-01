#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> u(n);
    for(auto &x: u) cin >> x;
    vector<vector<int>> cl(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        cl[x].push_back(y);
        cl[y].push_back(x);
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        bool ok = true;
        for(auto &j: cl[i]){
            if(u[i] == u[j]){
                ok = false;
                break;
            }
        }
        if(ok) continue;
        ans.push_back(i);
        u[i] = (u[i] + 1) % h;
        for(auto &j: cl[i]){
            if(u[i] == u[j]){
                ok = false;
                break;
            }
        }
        if(ok) break;
    }
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
    cout << "\n";
}