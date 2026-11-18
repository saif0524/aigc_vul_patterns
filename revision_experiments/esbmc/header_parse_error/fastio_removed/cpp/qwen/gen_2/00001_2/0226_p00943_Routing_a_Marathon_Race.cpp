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
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> min_cost(n, INT_MAX);
    for(int i = 0; i < n; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({c[i], i});
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();
            if(cost > min_cost[u]) continue;
            for(int v : adj[u]){
                if(dist[v] > dist[u] + c[v]){
                    dist[v] = dist[u] + c[v];
                    pq.push({dist[v], v});
                }
            }
        }
        for(int j = 0; j < n; j++) min_cost[j] = min(min_cost[j], dist[j]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += min_cost[i];
    cout << ans;
}