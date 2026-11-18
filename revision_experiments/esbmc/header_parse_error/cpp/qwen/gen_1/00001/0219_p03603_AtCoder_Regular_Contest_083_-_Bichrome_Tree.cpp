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

vector<vector<int>> adj;
vector<int> X, sum_black, sum_white;

bool dfs(int v, int parent_color) {
    int black = 0, white = 0;
    for (int u : adj[v]) {
        if (!dfs(u, parent_color ^ 1)) return false;
        black += sum_black[u];
        white += sum_white[u];
    }
    if (parent_color == 0) {
        if (black > X[v]) return false;
        sum_black[v] = X[v];
        sum_white[v] = white;
    } else {
        if (white > X[v]) return false;
        sum_black[v] = black;
        sum_white[v] = X[v];
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    sum_black.resize(N);
    sum_white.resize(N);
    X.resize(N);
    for (int i = 1; i < N; ++i) {
        int P;
        cin >> P;
        adj[P-1].push_back(i);
    }
    for (int i = 0; i < N; ++i) cin >> X[i];
    if (dfs(0, 0)) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";
}