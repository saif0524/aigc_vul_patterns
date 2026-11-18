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
const int maxn = 2e6 + 5;
long long l[maxn], r[maxn], ans[maxn];
int tl[maxn], tr[maxn], s[maxn];
int main() {
  ((void)0);
  ((void)0);
  int n;
  cin >> n;
  vector<long long> ds;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    ds.push_back(l[i]), ds.push_back(r[i]);
    ds.push_back(l[i] - 1), ds.push_back(l[i] + 1);
    ds.push_back(r[i] - 1), ds.push_back(r[i] + 1);
  }
  sort(ds.begin(), ds.end()),
      ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
  for (int i = 0; i < n; ++i) {
    tl[i] = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin();
    tr[i] = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin();
  }
  for (int i = 0; i < n; ++i) ++s[tl[i]], --s[tr[i] + 1];
  for (int i = 1; i < maxn; ++i) s[i] += s[i - 1];
  for (int i = 0; i < ds.size() - 1; ++i) {
    long long nxt = ds[i + 1] - 1;
    ans[s[i]] += nxt - ds[i] + 1;
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}