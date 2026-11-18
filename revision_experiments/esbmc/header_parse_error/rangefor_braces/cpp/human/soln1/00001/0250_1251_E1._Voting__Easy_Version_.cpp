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
const int N = 5050;
int a[N], b[N], pref[N];
vector<int> all[N];
int main() {
  int t;
  scanf("%i", &t);
  while (t--) {
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) all[i].clear();
    for (int i = 1; i <= n; i++)
      scanf("%i%i", &a[i], &b[i]), all[a[i]].push_back(b[i]);
    pref[0] = (int)all[0].size();
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + (int)all[i].size();
    multiset<int> val;
    long long ans = 0;
    int cnt = 0;
    for (int i = n - 1; i > 0; i--) {
      for (int j : all[i]) { val.insert(j); }
      while (pref[i - 1] + cnt < i) {
        cnt++;
        ans += *val.begin();
        val.erase(val.begin());
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}