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

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, -1));
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    long long ans = 1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(adj[i][j] == -1){
                ans = (ans * 2) % MOD;
            }
        }
    }
    vector<bool> vis(n+1, false);
    function<void(int)> dfs = [&](int node){
        vis[node] = true;
        for(int i=1;i<=n;i++){
            if(adj[node][i] != -1 && !vis[i]){
                dfs(i);
            }
        }
    };
    int components = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            components++;
        }
    }
    long long total_ways = 1;
    for(int i=0;i<components;i++){
        total_ways = (total_ways * 2) % MOD;
    }
    ans = (ans * total_ways) % MOD;
    cout << ans;
    return 0;
}