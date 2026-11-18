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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> centroid;
        vector<int> sz(n+1, 0);
        function<void(int, int)> dfs = [&](int u, int p){
            sz[u] = 1;
            bool is_centroid = true;
            int max_subtree = 0;
            for(auto v : adj[u]){
                if(v == p) continue;
                dfs(v, u);
                sz[u] += sz[v];
                max_subtree = max(max_subtree, sz[v]);
                if(sz[v] > n/2) is_centroid = false;
            }
            if(n - sz[u] > n/2) is_centroid = false;
            if(is_centroid) centroid.push_back(u);
        };
        dfs(1, -1);
        int c1 = centroid[0], c2 = -1;
        if(centroid.size() == 2) c2 = centroid[1];
        int cut_edge_x, cut_edge_y;
        if(c2 != -1){
            for(auto v : adj[c1]){
                if(v == c2){
                    cut_edge_x = c1;
                    cut_edge_y = c2;
                    break;
                }
            }
        }
        else{
            for(auto v : adj[c1]){
                cut_edge_x = c1;
                cut_edge_y = v;
                break;
            }
        }
        cout << cut_edge_x << " " << cut_edge_y << "\n";
        cout << cut_edge_x << " " << cut_edge_y << "\n";
    }
}