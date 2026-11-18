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
long long K, d, t;
int main() {
  scanf("%I64d%I64d%I64d", &K, &d, &t);
  d = ((K - 1) / d + 1) * d;
  t = t * 2;
  long long now = K * 2 + d - K;
  long long k1 = t / now, rem = t % now;
  long long ans = d * k1, ans2 = 0;
  if (rem <= K * 2)
    ans += rem / 2, ans2 = rem % 2;
  else
    ans += K + rem - K * 2;
  printf("%I64d", ans);
  if (ans2)
    cout << ".5" << endl;
  else
    cout << endl;
  return 0;
}