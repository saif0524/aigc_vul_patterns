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
string s, s1;
long long a, b, n;
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> s;
  cin >> s1;
  n = (long long)s.size();
  for (long long i = 0; i < n; i += 2) {
    if (s[i] == s1[i]) continue;
    if (s[i] == '8') {
      if (s1[i] == '(')
        b++;
      else
        a++;
    }
    if (s[i] == '(') {
      if (s1[i] == '[')
        b++;
      else
        a++;
    }
    if (s[i] == '[') {
      if (s1[i] == '8')
        b++;
      else
        a++;
    }
  }
  if (a == b) {
    cout << "TIE";
    return 0;
  }
  if (a > b)
    cout << "TEAM 1 WINS";
  else
    cout << "TEAM 2 WINS";
  return 0;
}