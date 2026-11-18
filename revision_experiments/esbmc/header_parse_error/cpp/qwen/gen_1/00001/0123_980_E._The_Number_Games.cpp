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

typedef long long ll;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges.push_back({max(a,b), {a,b}});
    }
    sort(edges.begin(), edges.end(), greater<>());
    DSU dsu(n);
    priority_queue<int, vector<int>, greater<>> pq;
    ll total = 0;
    for(auto &[w, e] : edges){
        auto [u, v] = e;
        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u, v);
            pq.push(w);
            total += (1LL << w);
        }
    }
    while(k--){
        total -= (1LL << pq.top());
        pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top()+1);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << ' ';
}