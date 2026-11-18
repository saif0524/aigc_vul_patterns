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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (int)(b); i--)

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(), (x).end()

#define MAXN 200005
#define INF 1000000000

int n, m, a, b;
vector<vi> G;
vii E;
vector<int> ans;
bool visited[MAXN], finished[MAXN];
int L[MAXN], H[MAXN];

void dfs(int u, int L_val, int H_val) {
    visited[u] = true;
    L[u] = L_val;
    H[u] = H_val;
    for (auto v : G[u]) {
        if (!visited[v]) dfs(v, L_val + 1, H_val + 1);
    }
    finished[u] = true;
}

signed main() {
    ((void)0); ((void)0);
    cin >> n >> m;
    G.resize(n);
    REP(i, m) {
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        E.pb(mp(a, b));
    }

    REP(i, n) if (!visited[i]) dfs(i, 0, 0);

    REP(i, m) {
        if (H[E[i].first] > H[E[i].second]) ans.pb(0);
        else ans.pb(1);
    }

    bool flag = true;
    REP(i, m) {
        if (H[E[i].first] == H[E[i].second] && L[E[i].first] != L[E[i].second]) flag = false;
    }

    if (flag) {
        cout << "YES\n";
        for (auto it : ans) cout << it;
        cout << "\n";
    }
    else cout << "NO\n";

    return 0;
}