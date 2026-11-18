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
    int u, v;
    long long s;
};

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    x = find(x, parent);
    y = find(y, parent);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<Edge> edges(m);
        for(auto &e: edges){
            cin >> e.u >> e.v >> e.s;
            e.u--; e.v--;
        }
        sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b){
            return a.s > b.s;
        });
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
        int mstEdges = 0;
        long long changes = 0;
        for(auto &e: edges){
            if(find(e.u, parent) != find(e.v, parent)){
                unite(e.u, e.v, parent, rank);
                if(e.s > k) changes += e.s - k;
                else if(e.s < k) changes += k - e.s;
                mstEdges++;
                if(mstEdges == n-1) break;
            }
        }
        cout << changes << "\n";
    }
}