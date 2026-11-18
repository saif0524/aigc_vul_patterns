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
long long n, a[1000005], add[1000005];
long long k;
bool used[1000005];
int main() {
  scanf("%lld%lld", &n, &k);
  long long sum = n * (n + 1) / 2;
  if (sum > k) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= n / 2; i++) {
    long long ch = n - 2 * i + 1;
    if (sum + ch <= k) {
      sum += ch;
      swap(a[i], a[n - i + 1]);
    } else {
      swap(a[i], a[k - sum + i]);
      sum = k;
      break;
    }
  }
  cout << sum << endl;
  for (int i = 1; i <= n; i++) cout << i << ' ';
  cout << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
  return 0;
}