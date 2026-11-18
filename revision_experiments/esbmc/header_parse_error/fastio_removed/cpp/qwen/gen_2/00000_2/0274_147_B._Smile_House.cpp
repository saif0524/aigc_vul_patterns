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

const int MAXN = 105;
const int INF = 1e9;
int dist[MAXN];
bool in_queue[MAXN];
vector<pair<int, int>> adj[MAXN];
int parent[MAXN];
int n, m;

bool spfa(int start) {
    fill(dist, dist + n + 1, INF);
    fill(parent, parent + n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    in_queue[start] = true;
    int node, next_node, weight;
    int count;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        in_queue[node] = false;
        for (auto edge : adj[node]) {
            next_node = edge.first;
            weight = edge.second;
            if (dist[node] + weight < dist[next_node]) {
                dist[next_node] = dist[node] + weight;
                parent[next_node] = node;
                if (!in_queue[next_node]) {
                    q.push(next_node);
                    in_queue[next_node] = true;
                    count++;
                    if (count > n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void find_cycle() {
    for (int i = 1; i <= n; ++i) {
        if (in_queue[i]) {
            int v = i;
            for (int j = 0; j < n; ++j) {
                v = parent[v];
            }
            int u = v;
            int cnt = 0;
            do {
                u = parent[u];
                cnt++;
            } while (u != v);
            cout << cnt;
            return;
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    int u, v, c, d;
    for(int i=0;i<m;i++){
        cin >> u >> v >> c >> d;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, d);
    }
    bool has_neg_cycle = false;
    for(int i=1;i<=n && !has_neg_cycle;i++){
        has_neg_cycle = spfa(i);
    }
    if(has_neg_cycle){
        find_cycle();
    } else {
        cout << 0;
    }
    return 0;
}