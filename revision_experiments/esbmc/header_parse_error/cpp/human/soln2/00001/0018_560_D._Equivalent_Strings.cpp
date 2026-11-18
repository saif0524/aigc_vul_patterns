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
bool havasar(string ::iterator s1, int n, string::iterator s2, int m) {
  if (n != m) return 0;
  if (n == 1) return (*s1) == (*s2);
  bool mark = true;
  string::iterator s3 = s1, s4 = s2;
  for (int i = 0; i < n; i++) {
    if ((*s1) != (*s2)) {
      mark = false;
      break;
    }
    s1++;
    s2++;
  }
  s1 = s3;
  s2 = s4;
  if (mark) return true;
  if (n % 2 == 1) return false;
  int tn = n / 2;
  int tm = m / 2;
  int kn = n - tn;
  int km = m - tm;
  return ((havasar(s1, tn, s2, tm) && havasar(s1 + tn, kn, s2 + tm, km)) ||
          (havasar(s1, tn, s2 + tm, km) && havasar(s1 + tn, kn, s2, tm)));
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << (havasar(s1.begin(), s1.size(), s2.begin(), s2.size()) ? "YES" : "NO")
       << endl;
  return 0;
}