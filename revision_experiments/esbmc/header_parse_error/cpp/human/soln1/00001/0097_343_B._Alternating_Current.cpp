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
const int INF = ~(1 << 31);
const double eps = 1e-6;
const long double PI = 3.1415926535;
const int MOD = 1e9 + 7;
int n, m;
int main() {
  string s;
  cin >> s;
  stack<int> st;
  for (int(i) = 0; (i) < (s.size()); ++(i)) {
    int g = s[i] == '+';
    if (st.size() && st.top() == g)
      st.pop();
    else
      st.push(g);
  }
  if (st.size() == 0)
    puts("Yes");
  else
    puts("No");
  return 0;
}