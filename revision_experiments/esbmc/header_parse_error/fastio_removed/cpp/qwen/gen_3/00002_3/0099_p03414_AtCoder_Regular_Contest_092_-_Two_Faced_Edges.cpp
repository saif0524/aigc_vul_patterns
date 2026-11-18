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

const int MAXN = 1005, MAXM = 200005;

vector<int> adj[MAXN], radj[MAXN];
bool vis[MAXN];
stack<int> stk;
int sccid[MAXN], scccnt;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    stk.push(u);
}

void rdfs(int u, int id) {
    vis[u] = true;
    sccid[u] = id;
    for (int v : radj[u]) {
        if (!vis[v]) rdfs(v, id);
    }
}

int main(){
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for(int i=0; i<M; i++){
        cin >> edges[i].first >> edges[i].second;
        adj[edges[i].first].push_back(edges[i].second);
        radj[edges[i].second].push_back(edges[i].first);
    }
    for(int i=1; i<=N; i++){
        if(!vis[i]) dfs(i);
    }
    memset(vis, false, sizeof(vis));
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        if(!vis[u]){
            rdfs(u, scccnt++);
        }
    }
    vector<int> in(scccnt, 0), out(scccnt, 0);
    for(auto [u, v] : edges){
        if(sccid[u] != sccid[v]){
            out[sccid[u]]++;
            in[sccid[v]]++;
        }
    }
    for(auto [u, v] : edges){
        int su = sccid[u], sv = sccid[v];
        if(su == sv){
            cout << "same\n";
        }
        else{
            bool change = false;
            if(out[su] == 1 && in[sv] == 1) change = true;
            if(out[sv] == 0) change = true;
            if(in[su] == 0) change = true;
            cout << (change ? "diff\n" : "same\n");
        }
    }
}