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

void solve() {
    int n, m;
    cin >> n >> m;
    int v = 3 * n;
    vector<vector<int>> adj(v + 1);
    vector<int> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back(u);
        edges.push_back(v);
    }

    vector<int> match(v + 1, -1);
    vector<bool> visited(v + 1, false);

    function<bool(int)> augment = [&](int u) -> bool {
        if(visited[u]) return false;
        visited[u] = true;
        for(int v : adj[u]) {
            if(match[v] == -1 || augment(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    };

    int matching_size = 0;
    for(int i = 1; i <= v; i++) {
        if(match[i] == -1) {
            fill(visited.begin(), visited.end(), false);
            if(augment(i)) {
                matching_size++;
            }
        }
    }

    if(matching_size == n) {
        cout << "Matching\n";
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int u = edges[2 * i], v = edges[2 * i + 1];
            if(match[u] == v) {
                ans.push_back(i + 1);
            }
        }
        for(int x : ans) cout << x << " ";
        cout << "\n";
        return;
    }

    vector<int> indSet;
    for(int i = 1; i <= v; i++) {
        if(!visited[i]) {
            indSet.push_back(i);
            if(indSet.size() == n) break;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    if(indSet.size() == n) {
        cout << "IndSet\n";
        for(int x : indSet) cout << x << " ";
        cout << "\n";
        return;
    }

    cout << "Impossible\n";
}

int main(){
    ((void)0);
    ((void)0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}