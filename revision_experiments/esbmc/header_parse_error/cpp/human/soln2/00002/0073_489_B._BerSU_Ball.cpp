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
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
vector<long long int> vis(500005), ans(500005), temp;
vector<long long int> alist[500005];
void dfs(long long int n) {
  vis[n] = 1;
  temp.push_back(n);
  for (auto i : alist[n]) {
    if (vis[i] == 0) dfs(i);
  }
}
void solve() {
  long long int b, g;
  cin >> b;
  long long int bz[b];
  for (long long int i = 0; i < b; i++) cin >> bz[i];
  cin >> g;
  long long int gz[g];
  for (long long int i = 0; i < g; i++) cin >> gz[i];
  sort(bz, bz + b);
  sort(gz, gz + g);
  long long int ans = 0;
  for (long long int i = 0; i < b; i++) {
    for (long long int j = 0; j < g; j++) {
      if (abs(bz[i] - gz[j]) <= 1) {
        ans++;
        gz[j] = 10000;
        break;
      }
    }
  }
  cout << ans;
}
signed main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}