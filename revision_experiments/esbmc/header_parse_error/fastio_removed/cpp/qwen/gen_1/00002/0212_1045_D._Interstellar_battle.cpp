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

const int MAXN = 100005;
const int MAXLOG = 20;
const double EPS = 1e-9;

vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], childCnt[MAXN];
double prob[MAXN];
int up[MAXN][MAXLOG];

void preprocess(int u, int p) {
    parent[u] = p;
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i < MAXLOG; ++i) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        } else {
            up[u][i] = -1;
        }
    }
    childCnt[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        preprocess(v, u);
        childCnt[u] += childCnt[v];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = MAXLOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = MAXLOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

double expectedComponents() {
    double ans = 0.0;
    for (int u = 0; u < n; ++u) {
        if (parent[u] == -1) continue;
        double p_u = prob[u];
        double p_p = prob[parent[u]];
        double q_u = 1.0 - p_u;
        double q_p = 1.0 - p_p;
        ans += (p_u * q_p * childCnt[u] + p_p * q_u + p_u * p_p) / (q_p + q_u * childCnt[u]);
    }
    ans += prob[0];
    return ans;
}

int n, q;

int main(){
    ((void)0);
    ((void)0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> prob[i];
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(up, -1, sizeof(up));
    preprocess(0, -1);
    cin >> q;
    while(q--){
        int u;
        double p;
        cin >> u >> p;
        prob[u] = p;
        cout << fixed << setprecision(5) << expectedComponents() << '\n';
    }
}