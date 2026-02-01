#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> edges;
vector<bool> included;
int tree_weight = 0;

void add_edge(int u, int v, int w) {
    tree_weight += w;
    included[v] = included[u] = true;
}

void remove_edge(int u, int v, int w) {
    tree_weight -= w;
    included[v] = included[u] = false;
}

int count_mst(int pos, vector<int>& weights) {
    if (pos == m) {
        if (count(included.begin(), included.end(), true) == n) {
            return tree_weight;
        }
        return 0;
    }
    
    int a = edges[pos].first;
    int b = edges[pos].second;
    int res = 0;
    
    if (!included[a] || !included[b]) {
        add_edge(a, b, weights[pos]);
        res = (res + count_mst(pos + 1, weights)) % MOD;
        remove_edge(a, b, weights[pos]);
    }
    
    res = (res + count_mst(pos + 1, weights)) % MOD;
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    edges.resize(m);
    included.resize(n + 1, false);
    
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    vector<int> weights(m);
    for (int i = 0; i < m; ++i) {
        weights[i] = i + 1;
    }
    
    int result = 0;
    do {
        result = (result + count_mst(0, weights)) % MOD;
    } while (next_permutation(weights.begin(), weights.end()));
    
    cout << result;
}