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
int N;
vector<int> xs, ys;
string generateFunc(int i, int x) {
  char str[1024];
  sprintf(str, "(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x / 2, i, i);
  return string(str);
}
string solve(vector<int>& xs) {
  string rv;
  rv += generateFunc(0, xs[0]);
  for (int i = 1; i < N; ++i)
    rv = "(" + rv + "+" + generateFunc(i, xs[i]) + ")";
  return rv;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    xs.emplace_back(x);
    ys.emplace_back(y);
  }
  cout << solve(xs) << endl;
  cout << solve(ys) << endl;
  return 0;
}