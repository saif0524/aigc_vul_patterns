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
const int maxN = 100 * 1000 + 100;
int a, b, c, t[maxN];
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) t[i] = s[i] - '0';
  for (int i = 0; i < s.size(); i++) a = max(a, (s[i] - '0'));
  cout << a << endl;
  for (int i = 0; i < s.size(); i++)
    while (t[i] > 0) {
      b = 0;
      for (int j = 0; j < s.size(); j++) {
        if (t[j] > 0)
          b = (b * 10) + 1;
        else
          b = (b * 10) + 0;
        t[j]--;
      }
      cout << b << " ";
    }
  cout << endl;
  return 0;
}