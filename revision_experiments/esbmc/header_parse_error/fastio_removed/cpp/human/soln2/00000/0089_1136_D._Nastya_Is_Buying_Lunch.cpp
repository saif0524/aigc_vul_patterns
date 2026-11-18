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
#pragma comment(linker, "/stack:256000000")
using namespace std;
mt19937_64 gen(time(NULL));
int const maxn = 3e5 + 5;
long long idx[maxn];
unordered_map<long long, bool> go[maxn];
signed main() {
  ((void)0);
  ((void)0);
  ((void)0);
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  for (long long i = 1; i <= n; i++) {
    long long t;
    cin >> t;
    idx[t] = i;
  }
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    if (idx[u] > idx[v])
      continue;
    else {
      u = idx[u];
      v = idx[v];
      go[u][v] = 1;
    }
  }
  vector<long long> kek = {0};
  long long ans = 0;
  for (long long i = 1; i <= n; i++) kek.push_back(i);
  for (long long i = n - 1; i >= 1; i--) {
    long long j = i;
    while (j < n && go[kek[j]][kek[j + 1]]) {
      if (kek[j + 1] == n) {
        ans++;
      }
      swap(kek[j], kek[j + 1]);
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}