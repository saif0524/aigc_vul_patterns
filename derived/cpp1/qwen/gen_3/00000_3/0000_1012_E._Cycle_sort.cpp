#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = i;
    sort(p.begin(), p.end(), [&](int i, int j){return a[i] < a[j];});
    int q = 0;
    vector<vector<int>> cycles;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(visited[i] || p[i] == i) continue;
        vector<int> cycle;
        int u = i;
        while(!visited[u]){
            visited[u] = true;
            cycle.push_back(u);
            u = p[u];
        }
        if(cycle.size() > s) {
            cout << -1;
            return 0;
        }
        s -= cycle.size();
        cycles.push_back(cycle);
        q++;
    }
    cout << q << "\n";
    for(auto &cycle : cycles){
        cout << cycle.size() << "\n";
        for(auto x : cycle) cout << x + 1 << " ";
        cout << "\n";
    }
}