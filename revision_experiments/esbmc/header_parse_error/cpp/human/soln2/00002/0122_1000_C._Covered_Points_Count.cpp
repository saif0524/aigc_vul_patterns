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
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, long long>> a(n);
  vector<long long> cval;
  for (auto &i : a) {
    scanf("%lld %lld", &i.first, &i.second);
    cval.push_back(i.first);
    cval.push_back(i.second + 1);
  }
  sort(cval.begin(), cval.end());
  cval.resize(unique(cval.begin(), cval.end()) - cval.begin());
  vector<int> cnt(2 * n);
  for (auto &i : a) {
    int posl = lower_bound(cval.begin(), cval.end(), i.first) - cval.begin();
    int posr =
        lower_bound(cval.begin(), cval.end(), i.second + 1) - cval.begin();
    ++cnt[posl];
    --cnt[posr];
  }
  for (int i = 1; i < 2 * n; ++i) cnt[i] += cnt[i - 1];
  vector<long long> ans(n + 1);
  for (int i = 1; i < 2 * n; ++i) ans[cnt[i - 1]] += cval[i] - cval[i - 1];
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  puts("");
  return 0;
}