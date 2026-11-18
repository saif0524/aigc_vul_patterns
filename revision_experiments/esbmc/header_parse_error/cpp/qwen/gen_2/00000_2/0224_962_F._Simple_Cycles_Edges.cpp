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

const int maxn = 1e5 + 5;

vector<int> adj[maxn];
int deg[maxn];
bool vis[maxn];
int n, m;
vector<pair<int, int>> edges;
int parent[maxn];
int dsu[maxn];
int sz[maxn];

int find(int x) {
    return x == dsu[x] ? x : dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
}

void dfs(int u, int p, int &cycle_start, int &cycle_end, bool &found) {
    vis[u] = 1;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            cycle_start = v;
            cycle_end = u;
            found = true;
            return;
        }
        dfs(v, u, cycle_start, cycle_end, found);
        if (found) return;
    }
}

vector<int> find_cycles() {
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cycle_start = -1, cycle_end = -1;
            bool found = false;
            dfs(i, -1, cycle_start, cycle_end, found);
            if (found) {
                vector<int> cycle;
                int u = cycle_end;
                while (u != cycle_start) {
                    cycle.push_back(u);
                    u = parent[u];
                }
                cycle.push_back(cycle_start);
                for (int j = 0; j < cycle.size(); j++) {
                    int v1 = cycle[j];
                    int v2 = cycle[(j + 1) % cycle.size()];
                    if (v1 > v2) swap(v1, v2);
                    for (int k = 0; k < m; k++) {
                        if (edges[k].first == v1 && edges[k].second == v2) {
                            result.push_back(k + 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u,v);
        dsu[u] = u;
        dsu[v] = v;
        sz[u] = sz[v] = 1;
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(i==1 || dsu[i]!=dsu[1]) dfs(i,-1,-1,-1,false);
    }
    vector<int> cycles = find_cycles();
    unordered_map<int,int> freq;
    for(int x : cycles) freq[x]++;
    vector<int> result;
    for(auto &[x,c] : freq) if(c==1) result.push_back(x);
    sort(result.begin(),result.end());
    cout << result.size() <<"\n";
    for(int x : result) cout << x << " ";
    cout << "\n";
}