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

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> edges;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionSets(int x, int y) {
        intfx = find(x);
        intfy = find(y);
        if (fx != fy) {
            if (rank[fx] < rank[fy])
                parent[fx] = fy;
            else if (rank[fx] > rank[fy])
                parent[fy] = fx;
            else {
                parent[fy] = fx;
                rank[fx]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    edges.resize(m + 1);
    vector<vector<int>> input(n, vector<int>(2));
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            cin >> input[i][0];
            input[i][1] = 0;
        } else {
            cin >> input[i][0] >> input[i][1];
        }
    }

    DisjointSet dsu(m + 1);

    for (int i = 0; i < n; i++) {
        int a = input[i][0];
        int b = input[i][1];

        if (dsu.find(a) != dsu.find(b)) {
            dsu.unionSets(a, b);
            used[i] = true;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (used[i])
            ans = (ans * 2) % MOD;
    }

    cout << ans << " " << count(used.begin(), used.end(), true) << endl;

    for (int i = 0; i < n; i++) {
        if (used[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}