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
  int n;
  cin >> n;
  stack<string> strs;
  while (n--) {
    string str;
    cin >> str;
    strs.push(str);
  }
  string now = strs.top();
  strs.pop();
  int cal1 = 0, cal2 = 0, res = 0, cnt = 0;
  char ch1 = now.front(), ch2 = now.back(), last = '$';
  for (int i = 0; i != (int)now.size(); ++i) {
    if (now[i] == ch1)
      ++cal1;
    else
      break;
  }
  for (int i = now.size() - 1; ~i; --i) {
    if (now[i] == ch2)
      ++cal2;
    else
      break;
  }
  for (const auto& ch : now) {
    if (ch != last) cnt = 0;
    res = max(res, ++cnt);
    last = ch;
  }
  bool check = res == (int)now.size();
  while (!strs.empty()) {
    now = strs.top();
    strs.pop();
    if (check) {
      int tmp1 = 0, tmp2 = 0, tmp = 0;
      for (int i = 0; i != (int)now.size(); ++i) {
        if (now[i] == ch1)
          ++tmp1;
        else
          break;
      }
      cal1 = tmp1 + (tmp1 + 1) * res;
      for (int i = now.size() - 1; ~i; --i) {
        if (now[i] == ch1)
          ++tmp2;
        else
          break;
      }
      cal2 = tmp2 + (tmp2 + 1) * res;
      cnt = 0;
      for (const auto& ch : now) {
        if (ch != ch1)
          cnt = 0;
        else
          tmp = max(tmp, ++cnt);
      }
      res = max(res, tmp + (tmp + 1) * res);
      check = tmp == (int)now.size();
    } else if (ch1 == ch2) {
      if (~now.find(ch1)) res = max(res, cal1 + cal2 + 1);
    } else {
      if (~now.find(ch1)) res = max(res, cal1 + 1);
      if (~now.find(ch2)) res = max(res, cal2 + 1);
    }
  }
  cout << res << endl;
}