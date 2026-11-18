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
const int N = 2e5 + 100;
int n, m, h[N], lev[N], Xor[N], cnt[N], deg[N];
vector<int> nxt[N], rnxt[N], vec[N];
set<int> s;
queue<int> q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    rnxt[y].push_back(x);
    nxt[x].push_back(y);
    ++deg[x];
  }
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : nxt[u]) { ++cnt[lev[v]]; }
    while (cnt[lev[u]]) ++lev[u];
    Xor[lev[u]] ^= h[u];
    for (auto v : nxt[u]) { --cnt[lev[v]]; }
    for (auto v : rnxt[u])
      { if (!--deg[v]) q.push(v); }
  }
  for (int i = n; ~i; --i)
    if (Xor[i]) {
      puts("WIN");
      for (int u = 1; u <= n; ++u)
        if (lev[u] == i && h[u] > (h[u] ^ Xor[i])) {
          h[u] ^= Xor[i];
          for (auto v : nxt[u])
            { if (Xor[lev[v]]) h[v] ^= Xor[lev[v]], Xor[lev[v]] = 0; }
          break;
        }
      for (int j = 1; j <= n; ++j) cout << h[j] << " ";
      puts("");
      return 0;
    }
  puts("LOSE");
  return 0;
}