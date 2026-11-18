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
  vector<int> a, b;
  int i = 0, j = s.size() - 1;
  while (i < j) {
    while (i < s.size() && s[i] == ')') i++;
    while (j >= 0 && s[j] == '(') j--;
    if (i < s.size() && j >= 0 && i < j) {
      a.push_back(i + 1);
      b.push_back(j + 1);
      i++;
      j--;
    }
  }
  if (a.empty()) {
    cout << 0 << "\n";
    return 0;
  }
  cout << 1 << "\n";
  cout << 2 * a.size() << "\n";
  for (auto i : a) cout << i << " ";
  reverse(b.begin(), b.end());
  for (auto i : b) cout << i << " ";
  cout << "\n";
  return 0;
}