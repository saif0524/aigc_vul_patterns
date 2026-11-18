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

const int MAXN = 1e5 + 10;
const int MAXM = 3e5 + 10;
const int MAXQ = 3e5 + 10;
const long long INF = 1e18;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAXN];

bool dijkstra(int source, int target, long long capacity, int n, int k) {
    vector<long long> distance(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;
    while (!pq.empty()) {
        long long currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDistance > distance[currentNode]) continue;
        for (const Edge& edge : graph[currentNode]) {
            long long nextDistance = currentDistance + edge.weight;
            int nextNode = edge.to;
            if (nextDistance <= capacity) {
                if (nextDistance < distance[nextNode]) {
                    distance[nextNode] = nextDistance;
                    pq.push({nextDistance, nextNode});
                }
            }
        }
        if (currentNode <= k) {
            for (const Edge& edge : graph[currentNode]) {
                long long nextDistance = edge.weight;
                int nextNode = edge.to;
                if (nextDistance < distance[nextNode]) {
                    distance[nextNode] = nextDistance;
                    pq.push({nextDistance, nextNode});
                }
            }
        }
    }
    return distance[target] != INF;
}

int main() {
    ((void)0);
    ((void)0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        long long low = 0, high = 1e9, res = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (dijkstra(a, b, mid, n, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}