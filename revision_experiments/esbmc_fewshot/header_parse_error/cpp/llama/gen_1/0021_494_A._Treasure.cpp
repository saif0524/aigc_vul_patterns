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
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt++;
    else if (s[i] == ')') cnt--;
    else cnt2++;
    if (cnt < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (cnt != cnt2) {
    cout << -1 << endl;
    return 0;
  }
  int cnt3 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt3++;
    else if (s[i] == ')') cnt3--;
    else {
      int x = 1;
      cnt3 += x;
      cout << x << endl;
    }
    if (cnt3 < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  return 0;
}