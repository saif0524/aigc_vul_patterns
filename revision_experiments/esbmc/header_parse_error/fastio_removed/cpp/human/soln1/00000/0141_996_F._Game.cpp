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
int N, R, vals[1 << 18];
double sum = 0;
int main() {
  ((void)0);
  ((void)0);
  cout << fixed << setprecision(18);
  cin >> N >> R;
  for (int i = 0; i < (1 << N); i++) {
    cin >> vals[i];
    sum += vals[i];
  }
  cout << sum / (1 << N) << '\n';
  for (int i = 0; i < R; i++) {
    int x, y;
    cin >> x >> y;
    sum += y - vals[x];
    vals[x] = y;
    cout << sum / (1 << N) << '\n';
  }
  return 0;
}