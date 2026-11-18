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
  ((void)0);
  ((void)0);
  ;
  int n;
  cin >> n;
  int g1 = 0, g2 = 0;
  int a[n / 2];
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
  }
  sort(a, a + n / 2);
  for (int i = 1; i <= n / 2; i++) {
    g1 += abs(a[i - 1] - (i * 2 - 1));
  }
  for (int i = 1; i <= n / 2; i++) {
    g2 += abs(a[i - 1] - (i * 2));
  }
  cout << min(g1, g2) << endl;
  return 0;
}