// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 3e5 + 5;
const long long INF = 1e18;

struct Edge {
    int to, rev;
    long long cap;
};

vector<Edge> adj[MAXN];
int level[MAXN], iter[MAXN];

void add_edge(int from, int to, long long cap) {
    adj[from].push_back({to, (int)adj[to].size(), cap});
    adj[to].push_back({from, (int)adj[from].size() - 1, 0});
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &e : adj[v]) {
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                if (e.to == t) return true;
                que.push(e.to);
            }
        }
    }
    return false;
}

long long dfs(int v, int t, long long f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)adj[v].size(); ++i) {
        Edge &e = adj[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            long long dtmp = dfs(e.to, t, min(f, e.cap));
            if (dtmp > 0) {
                e.cap -= dtmp;
                adj[e.to][e.rev].cap += dtmp;
                return dtmp;
            }
        }
    }
    return 0;
}

long long max_flow(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        memset(iter, 0, sizeof(iter));
        long long f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

bool check_capacity(int n, int m, int k, vector<Edge> &all_edges, int mid, int a, int b) {
    for (auto &e : adj) { e.clear(); }
    for (auto &e : all_edges) {
        if (e.cap > mid) continue;
        add_edge(e.to, e.rev, e.cap);
        add_edge(e.rev, e.to, 0);
    }
    int s = n + 1, t = n + 2;
    for (int i = 1; i <= k; ++i) {
        add_edge(s, i - 1, INF);
        add_edge(i - 1, t, INF);
    }
    add_edge(b - 1, a - 1, INF);
    return max_flow(s, t) > 0;
}

int main(){
    ((void)0);
    ((void)0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<Edge> all_edges;
    for(int i=0; i<m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        all_edges.push_back({u, v, w});
        all_edges.push_back({v, u, w});
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a == b){
            cout << 0 << "\n";
            continue;
        }
        int lo = 0, hi = (int)1e9, res = -1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check_capacity(n, m, k, all_edges, mid, a, b)){
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << res << "\n";
    }
}