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
    vector<int> p(n);
    for(auto &x: p) { cin >> x; }
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    queue<int> q;
    q.push(p.back());
    vector<int> dist(n+1, -1);
    dist[p.back()] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &neigh: graph[node]){
            if(dist[neigh] == -1){
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(dist[p[i]] != -1){
            ans = max(ans, n - i - 1 - dist[p[i]]);
        }
    }
    cout << ans;
}