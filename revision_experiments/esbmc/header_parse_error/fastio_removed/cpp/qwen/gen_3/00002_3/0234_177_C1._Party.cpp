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

int n, k, m;
vector<vector<int>> friends, dislikes;
vector<int> color;

bool is_valid_group(int mask) {
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            for (int j = i + 1; j < n; ++j) {
                if (mask & (1 << j)) {
                    for (int d : dislikes[i]) {
                        if (d == j) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool is_connected(int mask) {
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            start = i;
            break;
        }
    }
    if (start == -1) return true;

    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : friends[u]) {
            if (mask & (1 << v) && color[v] == 0) {
                color[v] = 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i) && color[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> k;
    friends.resize(n);
    dislikes.resize(n);
    for(int i = 0; i < k; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        dislikes[u].push_back(v);
        dislikes[v].push_back(u);
    }
    
    int ans = 0;
    for(int mask = 1; mask < (1 << n); ++mask){
        color.assign(n, 0);
        if(is_valid_group(mask) && is_connected(mask)){
            int cnt = __builtin_popcount(mask);
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}