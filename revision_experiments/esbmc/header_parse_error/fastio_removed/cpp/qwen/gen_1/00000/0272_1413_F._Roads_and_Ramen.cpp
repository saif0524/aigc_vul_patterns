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

struct Edge {
    int to, id;
    bool type;
};

int n, m;
vector<Edge> adj[500005];
bool flipped[500005];

int diameter(int u, int p, int &max_diameter, int &max_length, bool stone) {
    int max1 = 0, max2 = 0;
    for (auto &e : adj[u]) {
        if (e.to == p) continue;
        bool is_stone = e.type ^ flipped[e.id];
        int d = diameter(e.to, u, max_diameter, max_length, is_stone);
        if (is_stone) {
            if (d > max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) {
                max2 = d;
            }
        }
    }
    int total = max1 + max2;
    if (total > max_length) {
        max_length = total;
        max_diameter = stone ? 1 : 0;
    } else if (total == max_length) {
        if (stone) max_diameter = 1;
    }
    return max1 + 1;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, i, t == 1});
        adj[v].push_back({u, i, t == 1});
        flipped[i] = false;
    }
    cin >> m;
    int max_diameter = 0, max_length = 0;
    diameter(1, 0, max_diameter, max_length, true);
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        id--;
        flipped[id] = !flipped[id];
        max_diameter = 0;
        max_length = 0;
        diameter(1, 0, max_diameter, max_length, true);
        cout << (max_diameter ? max_length : max_length - 1) << '\n';
    }
}