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
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e4 + 20;
pair<int, int> a[N];
set<pair<int, int> > s;
int n;
void solve(int l, int r) {
  if (r - l < 2) return;
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid, r);
  int x = a[mid].first;
  for (int i = l; i < r; i++) s.insert(make_pair(x, a[i].second));
}
int main() {
  ((void)0), ((void)0), ((void)0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    s.insert(a[i]);
  }
  sort(a, a + n);
  solve(0, n);
  cout << s.size() << endl;
  for (auto x : s) cout << x.first << ' ' << x.second << endl;
}