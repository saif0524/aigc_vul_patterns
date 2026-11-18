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

const int MAXN = 200005;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int v, int &sz) {
    visited[v] = true;
    sz++;
    for (int to : adj[v]) {
        if (!visited[to]) {
            dfs(to, sz);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            bool found = false;
            for(const auto &[a, b] : edges){
                if((a == i && b == j) || (a == j && b == i)){
                    found = true;
                    break;
                }
            }
            if(!found){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> component_sizes;
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            int sz = 0;
            dfs(i, sz);
            component_sizes.push_back(sz);
        }
    }
    sort(component_sizes.begin(), component_sizes.end());
    cout << component_sizes.size() << "\n";
    for(int sz : component_sizes){
        cout << sz << " ";
    }
}