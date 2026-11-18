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

struct DisjointSet {
    vector<int> parent, rank, size, max_path;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        max_path.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] = max(rank[x], rank[y] + 1);
        size[x] += size[y];
        max_path[x] = max({max_path[x], max_path[y], max_path[x] + max_path[y] + 1});
    }

    int getMaxPath(int x) {
        return max_path[find(x)];
    }
};

int main(){
    ((void)0);
    ((void)0);
    int n, m, q;
    cin >> n >> m >> q;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        ds.unite(u, v);
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            cout << ds.getMaxPath(x) - 1 << "\n";
        }
        else{
            int x, y;
            cin >> x >> y;
            ds.unite(x, y);
        }
    }
}