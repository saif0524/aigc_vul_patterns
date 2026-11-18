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

long long comb(int n, int k) {
    if(k > n - k) k = n - k;
    long long res = 1;
    for(int i = 0; i < k; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

long long solve(int n, int m, vector<pair<int, int>> edges) {
    unordered_map<int, unordered_set<int>> adj;
    for(int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    long long alice_triangles = 0;
    for(int i = 1; i <= n; i++) {
        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            int j = *it;
            if(j < i) continue;
            for(auto it2 = adj[i].begin(); it2 != adj[i].end(); it2++) {
                int k = *it2;
                if(k > j) continue;
                if(adj[j].find(k) != adj[j].end()) {
                    alice_triangles++;
                }
            }
        }
    }
    long long total_triangles = comb(n, 3);
    long long bob_triangles = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                bool is_alice_triangle = adj[i].find(j) != adj[i].end() && 
                                        adj[j].find(k) != adj[j].end() && 
                                        adj[i].find(k) != adj[i].end();
                if(!is_alice_triangle) {
                    bob_triangles++;
                }
            }
        }
    }
    return alice_triangles + bob_triangles;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    long long ans = solve(n, m, edges);
    cout << ans << endl;

    return 0;
}