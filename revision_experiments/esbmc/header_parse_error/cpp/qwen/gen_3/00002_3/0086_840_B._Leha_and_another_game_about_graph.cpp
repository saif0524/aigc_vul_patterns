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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for(auto &x: d) cin >> x;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges.push_back({u,v});
    }
    vector<int> used(m, 0);
    vector<int> degree(n, 0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &e: adj[u]){
            if(!used[e]){
                used[e] = 1;
                int v = edges[e].first ^ edges[e].second ^ u;
                degree[u] ^= 1;
                degree[v] ^= 1;
                if(d[v] == 0 && degree[v] == 1){
                    q.push(v);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(degree[i] % 2 != d[i] && d[i] != -1){
            cout << -1;
            return 0;
        }
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        if(!used[i]){
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
}