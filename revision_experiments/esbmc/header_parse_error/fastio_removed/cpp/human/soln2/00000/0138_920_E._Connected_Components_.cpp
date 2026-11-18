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
long long n, m, u, v, cnt;
set<long long> adj[300005], rem;
set<long long>::iterator it;
vector<long long> ans;
void dfs(long long node) {
  rem.erase(node);
  cnt++;
  for (it = rem.begin(); it != rem.end();) {
    if (adj[node].count(*it)) {
      it++;
      continue;
    }
    long long tmp = *it;
    dfs(tmp);
    it = rem.lower_bound(tmp);
  }
  adj[node].clear();
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (long long i = 1; i <= n; i++) rem.insert(i);
  for (long long i = 1; i <= n; i++) {
    if (rem.count(i)) {
      cnt = 0;
      dfs(i);
      ans.push_back(cnt);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
  return 0;
}