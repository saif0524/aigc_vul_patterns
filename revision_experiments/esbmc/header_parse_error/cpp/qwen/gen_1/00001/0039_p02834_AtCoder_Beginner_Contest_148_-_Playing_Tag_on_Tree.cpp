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

vector<int> tree[100005];
int depth[100005];
int parent[100005];
int farthest[100005];

void dfs1(int node, int p, int d) {
    parent[node] = p;
    depth[node] = d;
    farthest[node] = node;
    for (int to : tree[node]) {
        if (to != p) {
            dfs1(to, node, d + 1);
            if (depth[farthest[node]] < depth[farthest[to]]) {
                farthest[node] = farthest[to];
            }
        }
    }
}

void dfs2(int node, int p) {
    for (int to : tree[node]) {
        if (to != p) {
            farthest[to] = farthest[node];
            if (depth[farthest[to]] < depth[farthest[to]]) {
                farthest[to] = farthest[to];
            }
            if (depth[farthest[node]] < depth[farthest[to]]) {
                farthest[node] = farthest[to];
            }
            dfs2(to, node);
        }
    }
}

int main(){
    int N, u, v;
    cin >> N >> u >> v;
    for(int i=1; i<N; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(u, -1, 0);
    int x = farthest[u];
    dfs1(x, -1, 0);
    int y = farthest[x];
    dfs1(y, -1, 0);
    dfs2(y, -1);
    int ans = -1;
    while(x != y){
        ans = max(ans, depth[farthest[x]]);
        x = parent[x];
    }
    ans = max(ans, depth[farthest[x]]);
    cout << (ans - depth[v] + 1) / 2;
}