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
  long long n;
  string s;
  map<string, bool> maap;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int k = 0; k < s.size(); k++) {
      for (int h = k; h < s.size(); h++) {
        maap[s.substr(k, h - k + 1)]++;
      }
    }
  }
  s.clear();
  s = "a";
  while (maap[s]) {
    s[s.size() - 1]++;
    if (s[s.size() - 1] > 'z' && s.size() == 1) {
      s = "aa";
    } else if (s.size() == 2 && s[s.size() - 1] > 'z') {
      s[0]++;
      s[s.size() - 1] = 'a';
      if (s[0] > 'z') s = "aaa";
    }
  }
  cout << s << endl;
  return 0;
}