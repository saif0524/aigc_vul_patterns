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
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sz(n+1, 0);
    vector<long long> fans(n+1, 0);
    function<void(int, int)> dfs = [&](int u, int p){
        sz[u] = 1;
        fans[u] = (1LL << u);
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            fans[u] += fans[v];
        }
    };
    dfs(1, -1);
    vector<pair<long long, int>> candidate;
    for(int i=2;i<=n;i++){
        candidate.emplace_back(fans[i], i);
    }
    sort(candidate.begin(), candidate.end());
    for(int i=0;i<k;i++){
        cout << candidate[i].second << (i < k-1 ? ' ' : '\n');
    }
}