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

const int MAXN = 405;
const int INF = 1e9;

int n, m, distTrain[MAXN], distBus[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        distTrain[i] = INF;
        distBus[i] = INF;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    distTrain[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (distTrain[v] > distTrain[u] + 1) {
                distTrain[v] = distTrain[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && find(adj[i].begin(), adj[i].end(), j) == adj[i].end()) {
                if (distBus[j] > distBus[i] + 1) {
                    distBus[j] = distBus[i] + 1;
                }
            }
        }
    }

    if (distTrain[n] == INF || distBus[n] == INF) {
        cout << "-1\n";
        return 0;
    }

    if (distTrain[n] == distBus[n]) {
        cout << distTrain[n] << "\n";
    } else {
        cout << max(distTrain[n], distBus[n]) << "\n";
    }

    return 0;
}