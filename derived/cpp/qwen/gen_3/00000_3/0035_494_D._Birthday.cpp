#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

vector<pair<int, ll>> adj[100005];
ll dp[100005], ans[100005], ds[100005];
int n, q;
vector<pair<int, int>> queries[100005];
bool done[100005];

void dfs1(int node, int parent, ll depth) {
    ds[node] = depth;
    for (auto &e : adj[node]) {
        int v = e.first;
        ll w = e.second;
        if (v == parent) continue;
        dfs1(v, node, depth + w);
        dp[node] = (dp[node] + dp[v] + w) % mod;
    }
}

void dfs2(int node, int parent) {
    for (auto &e : adj[node]) {
        int v = e.first;
        ll w = e.second;
        if (v == parent) continue;
        ll org = (dp[node] + mod - dp[v] - w) % mod;
        dp[v] = (dp[v] + dp[node] + w + ds[node] - ds[v]) % mod;
        dfs2(v, node);
        dp[node] = (dp[node] + org - dp[v] - w + ds[v] - ds[node] + mod) % mod;
    }
    for (auto &q : queries[node]) {
        int other = q.first, id = q.second;
        ans[id] = (dp[node] + dp[other] - ds[node] - ds[other] + mod) % mod;
    }
    done[node] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }
    dfs1(1, -1, 0);
    dfs2(1, -1);
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
}