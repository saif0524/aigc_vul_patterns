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
const int N = 2e5 + 5;
int n, a[N], cnt[N], pre[N], ans;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > cnt[mx]) mx = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i == mx) continue;
    if (cnt[i] == cnt[mx]) {
      ans = n;
      break;
    }
    mp.clear();
    int sum = 0;
    for (int j = 0; j <= n; j++) pre[j] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == mx) sum++;
      if (a[j] == i) sum--;
      pre[j] = sum;
      mp[sum]++;
    }
    for (int j = 0; j <= n; j++) {
      if (mp.find(pre[j]) != mp.end() && mp[pre[j]] > 1) {
        ans = max(ans, n - j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}