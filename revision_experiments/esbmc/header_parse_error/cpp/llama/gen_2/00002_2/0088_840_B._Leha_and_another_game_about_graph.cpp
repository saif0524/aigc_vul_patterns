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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5 + 5;
int n, m;
int d[MAXN];
vector<pii> adj[MAXN];
vector<int> ans;

void dfs(int u, int p, int id) {
    for (auto& pr : adj[u]) {
        int v = pr.first;
        if (v == p) continue;
        int new_id = id ^ pr.second;
        dfs(v, u, new_id);
    }
    if (d[u] != -1) {
        if (id % 2 != d[u]) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) cin >> d[i];
    int sum = 0;
    rep(i, 0, n) if (d[i] != -1) sum += d[i];
    if (sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back({v, i + 1});
        adj[v].push_back({u, i + 1});
    }
    dfs(0, -1, 0);
    rep(i, 0, n) if (d[i] == -1) {
        dfs(i, -1, 0);
        break;
    }
    int cnt = 0;
    rep(i, 0, ans.size()) if (ans[i]) cnt++;
    cout << cnt << endl;
    rep(i, 0, ans.size()) if (ans[i]) cout << i + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}