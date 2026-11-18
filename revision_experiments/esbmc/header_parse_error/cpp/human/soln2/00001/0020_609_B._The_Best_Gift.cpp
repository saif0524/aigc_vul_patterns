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
int genre[20], sum[20];
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> j;
    genre[j]++;
  }
  int s = 0;
  sum[1] = genre[1];
  for (i = 2; i <= m; i++) {
    sum[i] += (sum[i - 1] + genre[i]);
  }
  for (i = 1; i < m; i++) {
    s = s + genre[i] * (sum[m] - sum[i]);
  }
  cout << s << endl;
  return 0;
}