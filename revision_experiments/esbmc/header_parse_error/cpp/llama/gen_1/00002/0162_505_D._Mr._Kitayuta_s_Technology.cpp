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

const int N = 100005;

vector<int> graph[N];
int in_degree[N], out_degree[N], degree[N];
int parent[N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        in_degree[v]++;
        out_degree[u]++;
    }

    for (int i = 1; i <= n; i++) {
        degree[i] = out_degree[i] - in_degree[i];
    }

    int ans = 0;
    while (true) {
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (degree[i] >= 0) continue;
            for (int j : graph[i]) {
                if (degree[j] > 0) {
                    found = true;
                    degree[i]++;
                    degree[j]--;
                    ans++;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) break;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0) ans += degree[i];
    }

    cout << ans << endl;
    return 0;
}