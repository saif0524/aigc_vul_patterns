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

struct Hasher {
    size_t operator()(const vector<vector<size_t>>& v) const {
        size_t seed = 0;
        for (const auto& inner : v) {
            seed ^= inner.size() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

unordered_map<vector<vector<size_t>>, size_t, Hasher> memo;
vector<vector<int>> g;
vector<bool> visited;
vector<vector<size_t>> getSubtreeShapes(int u) {
    visited[u] = true;
    vector<vector<size_t>> subtrees;
    for (int v : g[u]) {
        if (!visited[v]) {
            subtrees.push_back(getSubtreeShapes(v));
        }
    }
    sort(subtrees.begin(), subtrees.end());
    return memo[subtrees] = vector<size_t>{subtrees.size()} + subtrees;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    visited.resize(n);
    size_t maxUnique = 0, best = 0;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            auto shapes = getSubtreeShapes(i);
            auto uniqueCount = memo.size();
            if(uniqueCount > maxUnique){
                maxUnique = uniqueCount;
                best = i;
            }
            memo.clear();
        }
    }
    cout << best + 1;
}