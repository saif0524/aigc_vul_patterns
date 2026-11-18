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
long long int fun(long long int a) {
  if (a == 0) return 0;
  if (a % 2 == 0)
    return fun(a / 2);
  else
    return fun(a / 2) + 1;
}
long long int sum[10000000];
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  long long int i, j, n, cnt = 0, temp;
  cin >> n;
  long long int ara[n];
  for (i = 0; i < n; i++) {
    cin >> temp;
    ara[i] = fun(temp);
    sum[ara[i]]++;
  }
  for (i = 0; i < 1000000; i++) {
    cnt += ((sum[i] * (sum[i] - 1)) / 2);
  }
  cout << cnt << endl;
  return 0;
}