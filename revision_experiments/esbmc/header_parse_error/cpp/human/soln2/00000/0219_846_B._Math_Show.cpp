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
int n, k, m, a[50], all, ans;
int _try(int x) {
  int t = m - x * all;
  int points = x * (k + 1);
  if (t < 0) return 0;
  for (int j = 0; j < k; j++)
    for (int i = 0; i < n - x; i++)
      if (t >= a[j]) t -= a[j], points++;
  return points;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]), all += a[i];
  sort(a, a + k);
  for (int i = 0; i <= n; i++) ans = max(ans, _try(i));
  cout << ans << endl;
}