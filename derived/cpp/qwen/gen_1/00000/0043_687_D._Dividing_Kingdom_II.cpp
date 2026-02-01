#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const long long INF = 1e18;

int n, m, q;
vector<pair<int, long long>> adj[MAXN];
vector<pair<pair<int, int>, long long>> edges;
pair<int, int> dsu[MAXN];
int sz[MAXN];

int find(int x) {
    if (dsu[x].first != x) {
        dsu[x].first = find(dsu[x].first);
    }
    return dsu[x].first;
}

void join(int x, int y, int curr_edge) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (sz[rootX] > sz[rootY]) {
            dsu[rootY].first = rootX;
            dsu[rootY].second = curr_edge;
            sz[rootX] += sz[rootY];
        } else {
            dsu[rootX].first = rootY;
            dsu[rootX].second = curr_edge;
            sz[rootY] += sz[rootX];
        }
    }
}

void clear_dsu() {
    for (int i = 1; i <= n; ++i) {
        dsu[i].first = i;
        dsu[i].second = -1;
        sz[i] = 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    vector<pair<pair<int, int>, long long>> sorted_edges = edges;
    sort(sorted_edges.begin(), sorted_edges.end(), [](const pair<pair<int, int>, long long>& a, const pair<pair<int, int>, long long>& b) {
        return a.second < b.second;
    });
    while(q--){
        int l, r;
        cin >> l >> r;
        clear_dsu();
        for(int i = 0; i < m; i++){
            if(i < l - 1 || i > r - 1){
                join(sorted_edges[i].first.first, sorted_edges[i].first.second, i);
            }
        }
        priority_queue<long long> pq;
        for(int i = 1; i <= n; i++){
            if(dsu[i].second != -1){
                pq.push(edges[dsu[i].second].second);
            }
        }
        if(pq.empty()){
            cout << -1 << "\n";
        }
        else{
            cout << pq.top() << "\n";
        }
    }
}