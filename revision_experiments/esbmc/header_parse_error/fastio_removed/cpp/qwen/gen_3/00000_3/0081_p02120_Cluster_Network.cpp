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
vector<int> adj[MAXN];
int weight[MAXN];
int par[MAXN], sz[MAXN], perf[MAXN];
bool removed[MAXN];
int n, m;

int getParent(int x) {
    while (par[x] != x) x = par[x];
    return x;
}

void merge(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        perf[x] += perf[y];
    }
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> weight[i], perf[i] = weight[i], par[i] = i, sz[i] = 1;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=n; i>=1; i--){
        removed[i] = true;
        for(auto &j: adj[i]){
            if(!removed[j]) merge(i, j);
        }
        int p = getParent(i);
        cout << perf[p] << "\n";
    }
}