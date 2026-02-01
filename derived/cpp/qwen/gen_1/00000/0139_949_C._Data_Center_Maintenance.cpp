#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> u(n);
    for(auto &x: u) cin >> x;
    vector<set<int>> cl(h);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cl[u[a]].insert(min(a, b));
        cl[u[b]].insert(max(a, b));
    }
    vector<int> ans;
    for(int i = 0; i < h; ++i){
        set<int> toAdd;
        for(auto x: cl[i]){
            if(cl[(i+1)%h].count(x)){
                toAdd.insert(x);
            }
        }
        for(auto x: toAdd){
            cl[i].erase(x);
            cl[(i+1)%h].erase(x);
            ans.push_back(x+1);
        }
        if(ans.size() == n) break;
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    cout << "\n";
}