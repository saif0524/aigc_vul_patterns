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
long long mod = 1000000007;
vector<vector<int> > v(100001);
vector<int> vis(100001);
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
int dfs(int src) {
  stack<int> st;
  int cnt = 0;
  st.push(src);
  vis[src] = 1;
  cnt++;
  while (!st.empty()) {
    int x = st.top();
    st.pop();
    if (!vis[x]) {
      cnt++;
      vis[x] = 1;
    }
    for (int i = 0; i < v[x].size(); i++) {
      if (vis[v[x][i]] == 0) st.push(v[x][i]);
    }
  }
  return cnt;
}
int main() {
  ((void)0);
  ((void)0);
  int n, k;
  cin >> n >> k;
  fill(vis.begin(), vis.end(), 0);
  for (int i = 0; i < v.size(); i++) v[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    if (c == 0) {
      v[x].push_back(y);
      v[y].push_back(x);
    }
  }
  long long ans = binpow(n, k);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = (mod + ans - binpow(dfs(i), k)) % mod;
    }
  }
  cout << ans << endl;
}