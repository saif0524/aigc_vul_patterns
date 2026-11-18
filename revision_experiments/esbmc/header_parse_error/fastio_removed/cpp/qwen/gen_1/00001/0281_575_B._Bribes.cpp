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

struct Edge {
    int to, cost, type;
};

vector<Edge> adj[100005];
int dist[100005][2];
bool vis[100005];

void dijkstra(int start) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {start, 0}});
    dist[start][0] = dist[start][1] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second.first;
        int t = pq.top().second.second;
        pq.pop();

        if (vis[u] && dist[u][t] <= cost) continue;
        vis[u] = true;

        for (const Edge& e : adj[u]) {
            int v = e.to;
            int nc = e.cost;
            int nt = e.type;

            if (t == 1 && nt == 1) continue;

            int newCost = cost;
            if (nt == 1 && t == 0) {
                newCost += nc;
            } else if (nt == 1 && t == 1) {
                newCost += (nc << 1);
            }

            if (newCost < dist[v][nt]) {
                dist[v][nt] = newCost;
                pq.push({newCost, {v, nt}});
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, 1000, x});
        if(x == 0) adj[b].push_back({a, 1000, x});
    }
    int k;
    cin >> k;
    vector<int> stops(k);
    for(int i=0;i<k;i++) cin >> stops[i];
    for(int i=1;i<=n;i++) dist[i][0] = dist[i][1] = INT_MAX;
    dijkstra(1);
    long long totalCost = 0;
    for(int i=0;i<k-1;i++){
        totalCost += min(dist[stops[i]][0], dist[stops[i]][1]);
        if(stops[i] == stops[i+1]) continue;
        int costForward = dist[stops[i]][0] + 1000;
        int costBackward = dist[stops[i+1]][1] + (dist[stops[i+1]][1] == INT_MAX ? 1000 : 2000);
        totalCost += min(costForward, costBackward);
    }
    totalCost += min(dist[stops.back()][0], dist[stops.back()][1]);
    cout << (totalCost % MOD);
}