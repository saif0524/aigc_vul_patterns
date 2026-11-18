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

const int MAXN = 100005;
const long long INF = 1e18;

vector<pair<int, long long>> adj[MAXN];
vector<int> special;

long long dijkstra(int start, const vector<int>& targets) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(MAXN, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto& [v, w] : adj[u]) {
            if (dist[v] > max(d, w)) {
                dist[v] = max(d, w);
                pq.push({dist[v], v});
            }
        }
    }
    long long max_dist = 0;
    for (int t : targets) {
        max_dist = max(max_dist, dist[t]);
    }
    return max_dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    special.resize(k);
    for(int &x: special) cin >> x;
    for(int i=0;i<m;i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<long long> results;
    for(int s: special){
        results.push_back(dijkstra(s, special));
    }
    for(long long res: results){
        cout << res << ' ';
    }
    return 0;
}