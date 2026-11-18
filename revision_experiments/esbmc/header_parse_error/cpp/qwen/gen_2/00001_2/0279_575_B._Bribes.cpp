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

typedef long long ll;

const int MAXN = 1e5+5;
const int MAXK = 1e6+5;
const ll MOD = 1e9+7;

vector<pair<int,int>> adj[MAXN];
vector<int> route;
int parent[MAXN], level[MAXN];
bitset<MAXN> visited;
pair<int,int> subtreecosts[MAXN];

void dfs(int u, int p, int l) {
    parent[u] = p;
    level[u] = l;
    visited[u] = true;
    for(auto [v, is_directed] : adj[u]) {
        if(visited[v]) continue;
        dfs(v, u, l+1);
        if(!is_directed) {
            subtreecosts[u].first += subtreecosts[v].first + 1;
            subtreecosts[u].second += subtreecosts[v].second + 2;
        }
    }
}

int lca(int a, int b) {
    if(level[a] < level[b]) swap(a,b);
    while(level[a] > level[b]) a = parent[a];
    while(a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=1;i<N;i++){
        int a,b,x;
        cin >> a >> b >> x;
        adj[a].emplace_back(b,x);
        adj[b].emplace_back(a,x);
    }
    dfs(1,0,0);
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int x;
        cin >> x;
        route.push_back(x);
    }
    ll ans = 0;
    int last = 1;
    for(auto x : route){
        if(x==last) continue;
        int meet = lca(x,last);
        if(level[last] < level[meet]) swap(last,x);
        while(level[last] > level[meet]){
            if(parent[last] == meet){
                ans += (subtreecosts[last].first - subtreecosts[x].first + MOD) % MOD;
            }
            else{
                ans += (subtreecosts[last].first - subtreecosts[last^parent[last]].first + MOD) % MOD;
            }
            last = parent[last];
        }
        while(last != meet){
            ans += (subtreecosts[last].second - subtreecosts[last^meet].second + MOD) % MOD;
            last = parent[last];
        }
        last = x;
    }
    cout << ans % MOD;
}