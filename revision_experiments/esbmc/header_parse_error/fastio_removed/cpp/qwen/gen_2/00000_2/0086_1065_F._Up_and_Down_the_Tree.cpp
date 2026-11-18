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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    vector<int> depth(n+1, 0);
    vector<int> leaves(n+1, 0);
    function<void(int)> dfs = [&](int node){
        if(adj[node].empty()){
            leaves[node] = 1;
            return;
        }
        for(int child : adj[node]){
            depth[child] = depth[node] + 1;
            dfs(child);
            leaves[node] += leaves[child];
        }
    };
    dfs(1);
    vector<int> q(n+1, 0);
    function<void(int,int,int)> dfs2 = [&](int node, int parent, int max_up){
        int max_leaves = 0;
        for(int child : adj[node]){
            if(depth[node] - depth[child] > k){
                int leaves_below = leaves[child];
                q[node] += leaves_below;
                max_leaves = max(max_leaves, leaves_below);
            }
        }
        for(int child : adj[node]){
            if(depth[node] - depth[child] > k){
                leaves[child] = q[node] - leaves[child] + max_up;
            }
            dfs2(child, node, max(max_up, leaves[node] - leaves[child]));
        }
    };
    dfs2(1, 0, 0);
    int result = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].empty()){
            result = max(result, leaves[i]);
        }
    }
    cout << result << "\n";
}