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
bool vis[200010];
void dfs(vector<long long int> arr[], long long int i, long long int temp) {
  vis[i] = true;
  for (long long int u : arr[i]) {
    if (!vis[u] and u != temp) dfs(arr, u, temp);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, a, b, u, v;
    cin >> n >> m >> a >> b;
    vector<long long int> arr[n + 1];
    for (long long int i = 0; i < m; i++) {
      cin >> u >> v;
      arr[u].push_back(v);
      arr[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    dfs(arr, a, b);
    unordered_set<long long int> us1;
    for (long long int i = 1; i <= n; i++) {
      if (vis[i]) us1.insert(i);
    }
    us1.erase(a);
    memset(vis, false, sizeof(vis));
    dfs(arr, b, a);
    unordered_set<long long int> us2;
    for (long long int i = 1; i <= n; i++) {
      if (vis[i]) us2.insert(i);
    }
    us2.erase(b);
    long long int ans1 = 0, ans2 = 0;
    for (auto val : us1) {
      if (us2.find(val) == us2.end()) ans1++;
    }
    for (auto val : us2) {
      if (us1.find(val) == us1.end()) ans2++;
    }
    cout << ans1 * ans2 << "\n";
  }
  return 0;
}