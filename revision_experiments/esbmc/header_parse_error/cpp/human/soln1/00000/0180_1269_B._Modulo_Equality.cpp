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
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> ar(n);
  vector<ll> br(n);
  map<ll, ll> a, b;
  for (auto &x : ar) {
    cin >> x;
    a[x]++;
  }
  for (auto &x : br) {
    cin >> x;
    b[x]++;
  }
  ll res = 1.01e18;
  for (int i = 0; i < n; ++i) {
    ll x = (br[i] - ar[0] + m) % m;
    bool can = true;
    for (auto ex : a) {
      can &= (ex.second == b[(ex.first + x) % m]);
    }
    if (can) res = min(res, x);
  }
  cout << res << '\n';
  return 0;
}