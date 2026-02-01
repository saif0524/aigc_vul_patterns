#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k1;
    cin >> k1;
    vector<int> x(k1);
    for(int &a : x) cin >> a, a--;
    int k2;
    cin >> k2;
    vector<int> y(k2);
    for(int &b : y) cin >> b;
    
    map<int, int> mx, my;
    for(auto &a : x) mx[a] = 1;
    for(auto &b : y) my[b] = 1;

    int c1 = 0, c2 = 0;
    for(auto &[v, _] : mx) {
        cout << "A " << v + 1 << endl;
        cin >> c1;
        if(c1 == -1) exit(0);
        if(my.find(c1) != my.end()) {
            cout << "C " << v + 1 << endl;
            return;
        }
    }
    for(auto &[v, _] : my) {
        cout << "B " << v << endl;
        cin >> c2;
        if(c2 == -1) exit(0);
        if(mx.find(c2-1) != mx.end()) {
            cout << "C " << c2 << endl;
            return;
        }
    }
    cout << "C -1" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}