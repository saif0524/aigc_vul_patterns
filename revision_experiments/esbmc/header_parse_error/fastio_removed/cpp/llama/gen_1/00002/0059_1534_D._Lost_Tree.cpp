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

const int N = 2005;
int n, dist[N][N], depth[N];
bool vis[N];

void query(int u) {
    cout << "? " << u << endl;
    for (int i = 1; i <= n; i++) {
        cin >> dist[u][i];
    }
}

void dfs(int u, int fa, int dep) {
    vis[u] = true;
    depth[u] = dep;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && dist[u][v] == dep + 1) {
            dfs(v, u, dep + 1);
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        query(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!dist[i][j]) {
                dist[i][j] = dist[j][i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, 0);
        }
    }

    cout << "!" << endl;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if ((abs(depth[i] - depth[j]) == 1) && dist[i][j] == abs(depth[i] - depth[j])) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}