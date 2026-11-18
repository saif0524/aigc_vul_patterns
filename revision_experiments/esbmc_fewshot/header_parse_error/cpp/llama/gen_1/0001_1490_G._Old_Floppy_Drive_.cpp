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
const int N = 2e5 + 5;
int a[N];
ll pre[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    ll mx = pre[n];
    for (int i = 1; i <= m; i++) {
      ll x;
      cin >> x;
      if (mx < x && pre[n] <= 0) {
        cout << -1 << " ";
        continue;
      }
      if (pre[n] > 0) {
        ll ans = 0;
        if (x > mx) {
          ll tmp = (x - mx + pre[n] - 1) / pre[n];
          ans += tmp * n;
          x -= tmp * pre[n];
        }
        int l = 1, r = n;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (pre[mid] >= x)
            r = mid;
          else
            l = mid + 1;
        }
        ans += l - 1;
        cout << ans << " ";
      } else {
        int l = 1, r = n;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (pre[mid] >= x)
            r = mid;
          else
            l = mid + 1;
        }
        cout << l - 1 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}