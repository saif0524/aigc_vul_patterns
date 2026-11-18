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

const double EPS = 1e-8;
const int MAX_N = 1e5 + 5;

int N;
double P[MAX_N];
vector<int> adj[MAX_N];
double res;

void dfs(int u, int p, double sp) {
    res += (1 - P[u]) * sp;
    double cs = (1 - P[u]) * sp;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, cs);
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        res = 0;
        int j;
        double np;
        cin >> j >> np;
        double op = P[j];
        P[j] = np;
        res += 1 - P[0];
        for (int v : adj[0]) {
            dfs(v, 0, P[0]);
        }
        printf("%.5f\n", res);
        P[j] = op;
    }

    return 0;
}