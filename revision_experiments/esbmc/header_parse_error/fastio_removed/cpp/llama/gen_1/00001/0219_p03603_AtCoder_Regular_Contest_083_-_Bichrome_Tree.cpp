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

const int MAXN = 1005;

vector<int> g[MAXN];
int x[MAXN], p[MAXN];
bool visited[MAXN];
long long total[MAXN];

void dfs(int u) {
    visited[u] = true;
    total[u] = x[u];
    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs(v);
            total[u] += total[v];
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (x[i] > total[i] || (total[i] - x[i]) % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
}