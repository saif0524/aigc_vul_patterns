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

const int N = 1e5 + 5;

vector<int> adj[N];
int depth[N];
int LCA[N][20];

void dfs(int u, int p) {
    LCA[u][0] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void preprocess(int n) {
    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= n; i++) {
            if (LCA[i][k-1] != -1) {
                LCA[i][k] = LCA[LCA[i][k-1]][k-1];
            }
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = 19; k >= 0; k--) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = LCA[u][k];
        }
    }
    if (u == v) return u;
    for (int k = 19; k >= 0; k--) {
        if (LCA[u][k] != LCA[v][k]) {
            u = LCA[u][k];
            v = LCA[v][k];
        }
    }
    return LCA[u][0];
}

int distance(int u, int v, int lca) {
    return depth[u] + depth[v] - 2 * depth[lca];
}

bool check(int x, int y, int a, int b, long long k) {
    int lcaAX = findLCA(a, x);
    int lcaBX = findLCA(b, x);
    int lcaBY = findLCA(b, y);
    int lcaAY = findLCA(a, y);
    int lcaAB = findLCA(a, b);
    int lcaXY = findLCA(x, y);

    long long distAX = distance(a, x, lcaAX);
    long long distBX = distance(b, x, lcaBX);
    long long distBY = distance(b, y, lcaBY);
    long long distAY = distance(a, y, lcaAY);
    long long distAB = distance(a, b, lcaAB);
    long long distXY = distance(x, y, lcaXY);

    long long path1 = distAX + distBX + distXY + 1;
    long long path2 = distAY + distBY + distXY + 1;
    long long path3 = distAB;

    return (k >= path3 && (k - path3) % 2 == 0) ||
           (k >= path1 && (k - path1) % 2 == 0) ||
           (k >= path2 && (k - path2) % 2 == 0);
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1]=0;
    memset(LCA, -1, sizeof LCA);
    dfs(1, -1);
    preprocess(n);
    int q;
    cin >> q;
    while(q--){
        int x, y, a, b;
        long long k;
        cin >> x >> y >> a >> b >> k;
        if(check(x, y, a, b, k)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}