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

struct UnionFind {
    vector<int> parent, rank, longest_path, size;

    UnionFind(int n) : parent(n), rank(n), longest_path(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) ++rank[u];

        int new_longest = max(longest_path[u], longest_path[v]);
        if (size[u] < size[v]) {
            swap(size[u], size[v]);
            swap(longest_path[u], longest_path[v]);
        }
        for (int len = 0; len + len < size[v]; ++len) {
            new_longest = max(new_longest, len + 1 + longest_path[v] - len);
        }
        longest_path[u] = new_longest;
        size[u] += size[v];
    }

    int get_longest_path(int u) {
        return longest_path[find(u)];
    }
};

int main() {
    ((void)0);
    ((void)0);
    int n, m, q;
    cin >> n >> m >> q;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        uf.merge(u, v);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            --x;
            cout << uf.get_longest_path(x) << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            --x; --y;
            uf.merge(x, y);
        }
    }
}