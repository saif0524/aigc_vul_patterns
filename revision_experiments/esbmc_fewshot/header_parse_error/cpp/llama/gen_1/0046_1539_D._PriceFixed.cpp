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
typedef pair<ll, ll> pii;
const int maxn = 1e5 + 10;
pii a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a, a + n);
  ll ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first > cnt) {
      ll need = a[i].first - cnt;
      ans += 2 * min(need, a[i].second);
      cnt += min(need, a[i].second);
      if (need > a[i].second) {
        ans += a[i].second;
        cnt += a[i].second;
      } else {
        ans += a[i].second - need;
        cnt += a[i].second - need;
      }
    } else {
      ans += a[i].second;
      cnt += a[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}