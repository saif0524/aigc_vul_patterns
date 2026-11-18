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
const int maxn = 100005;
const int maxk = 105;
vector<pair<int, long double> > f, tmp;
long double g[maxn], t[maxn];
long double ans;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  f.push_back(make_pair(1, 1.0));
  for (int i = 0; i < n; ++i) {
    tmp.clear();
    for (int k = 0; k < (int)f.size(); ++k) {
      int j = f[k].first;
      long double p = f[k].second;
      if (p < 1e-15) continue;
      g[i + 1] += p * (j * 1.0 / (j + 1)) * ((j + 1) / 2.0);
      tmp.push_back(make_pair(j, p * (j * 1.0 / (j + 1))));
      g[i + 1] += p * (1.0 / (j + 1)) * j;
      tmp.push_back(make_pair(j + 1, p * (1.0 / (j + 1))));
    }
    pair<int, long double> last = tmp[0];
    f.clear();
    for (int k = 1; k < (int)tmp.size(); ++k)
      if (tmp[k].first == last.first)
        last.second += tmp[k].second;
      else {
        f.push_back(last);
        last = tmp[k];
      }
    f.push_back(last);
  }
  for (int i = 1; i <= n; ++i) g[i] += g[i - 1];
  if (k > 1) {
    t[0] = log(1);
    for (int i = 1; i <= n; ++i) t[0] = t[0] + log(k - 1) - log(k);
    for (int i = 1; i <= n; ++i)
      t[i] = t[i - 1] + log(n - i + 1) - log(i) - log(k - 1);
    for (int i = 1; i <= n; ++i) t[i] = exp(t[i]);
  } else {
    t[n] = 1;
  }
  for (int i = 0; i <= n; ++i) ans += g[i] * t[i];
  ans *= k;
  printf("%.100lf\n", (double)ans);
  return 0;
}