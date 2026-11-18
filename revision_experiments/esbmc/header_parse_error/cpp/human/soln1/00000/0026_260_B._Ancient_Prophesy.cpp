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
char s[100005];
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> my;
void check(char* s) {
  if (((s[0]) >= '0' && (s[0]) <= '9') && ((s[1]) >= '0' && (s[1]) <= '9') &&
      ((s[3]) >= '0' && (s[3]) <= '9') && ((s[4]) >= '0' && (s[4]) <= '9') &&
      ((s[6]) >= '0' && (s[6]) <= '9') && ((s[7]) >= '0' && (s[7]) <= '9') &&
      ((s[8]) >= '0' && (s[8]) <= '9') && ((s[9]) >= '0' && (s[9]) <= '9') &&
      s[2] == '-' && s[5] == '-') {
    int d = atoi(s);
    int m = atoi(s + 3);
    int y = atoi(string(s + 6, s + 10).c_str());
    if (m <= 12 && d > 0 && d <= day[m - 1] && y >= 2013 && y <= 2015) {
      ++my[string(s, s + 10)];
    }
  }
}
int main() {
  gets(s);
  int n = strlen(s);
  for (int i = 0; i + 10 <= n; ++i) check(s + i);
  string res("");
  int max = -1;
  for (typeof((my).begin()) it = (my).begin(), _e = (my).end(); it != _e; ++it)
    if (it->second > max) {
      max = it->second;
      res = it->first;
    }
  cout << res << endl;
  return 0;
}