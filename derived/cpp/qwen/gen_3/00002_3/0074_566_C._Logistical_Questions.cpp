#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj;
vector<long long> sum_down, sum_up;

void dfs1(int u, int p) {
    for (auto &[v, l] : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sum_down[u] += sum_down[v] + l * adj[v].size();
    }
}

void dfs2(int u, int p, int n) {
    for (auto &[v, l] : adj[u]) {
        if (v == p) continue;
        sum_up[v] = sum_up[u] + sum_down[u] - sum_down[v] - adj[v].size() * l;
        sum_up[v] += sum_up[u] + n - adj[v].size() - l * (n - adj[v].size());
        dfs2(v, u, n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> w(n);
    for(auto &x: w) cin >> x;
    adj.resize(n);
    for(int i=1;i<n;i++){
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }
    sum_down.assign(n, 0);
    sum_up.assign(n, 0);
    dfs1(0, -1);
    dfs2(0, -1, n);
    for(int i=0;i<n;i++){
        sum_down[i] += w[i] * adj[i].size();
    }
    for(int i=0;i<n;i++){
        sum_up[i] += sum_down[i];
    }
    int best=0;
    for(int i=1;i<n;i++){
        if(sum_up[i] < sum_up[best]){
            best = i;
        }
    }
    cout << best+1 << " " << fixed << setprecision(10) << sqrtl(sum_up[best]) << "\n";
    return 0;
}