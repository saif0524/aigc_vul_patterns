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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    vector<int> depth(n+1,0);
    vector<int> leaf_count(n+1,0);
    function<void(int,int)> dfs = [&](int node, int d){
        depth[node] = d;
        if(adj[node].empty()){
            leaf_count[node] = 1;
            return;
        }
        for(int child : adj[node]){
            dfs(child, d+1);
            leaf_count[node] += leaf_count[child];
        }
    };
    dfs(1,0);
    vector<int> ans(n+1,0);
    function<void(int,int,int,int)> dfs2 = [&](int node, int d, int max_ancestor_depth, int max_ancestor_leaves){
        ans[node] = max(ans[node], max_ancestor_leaves);
        if(adj[node].empty()){
            return;
        }
        for(int child : adj[node]){
            dfs2(child, d+1, max(max_ancestor_depth, depth[child]-k), max(max_ancestor_leaves, leaf_count[child]));
        }
        int sum = 0;
        vector<int> partial_sums;
        for(int child : adj[node]){
            partial_sums.push_back(sum);
            sum += leaf_count[child];
        }
        for(int i=0;i<adj[node].size();i++){
            int child = adj[node][i];
            int left = (i==0?0:partial_sums[i-1]);
            int right = sum - partial_sums[i] - leaf_count[child];
            int new_max_ancestor_depth = max(max_ancestor_depth, depth[child]-k);
            int new_max_ancestor_leaves = max(max_ancestor_leaves, left + right);
            dfs2(child, d+1, new_max_ancestor_depth, new_max_ancestor_leaves);
        }
    };
    dfs2(1,0,0,0);
    int result = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].empty()){
            result = max(result, ans[i]);
        }
    }
    cout << result;
}