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
typedef long long ll;
const int N = 3e5 + 5;
int n, k;
ll a[N];
ll ans = 1e18;
void dfs(int pos, ll sum, vector<int> &vis) {
  if (pos == n) {
    ans = min(ans, sum);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    dfs(pos + 1, sum + abs(a[i] - a[pos - 1]), vis);
    vis[i] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < k; i++) {
    vector<int> vis(n, 0);
    vis[i] = 1;
    dfs(1, 0, vis);
  }
  cout << ans << endl;
  return 0;
}