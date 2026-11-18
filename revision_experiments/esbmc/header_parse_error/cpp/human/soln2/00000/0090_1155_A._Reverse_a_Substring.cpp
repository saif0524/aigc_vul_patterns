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
  string str;
  cin >> str;
  bool ok = false;
  int l = -1, r = -1;
  for (int i = 1; i < str.length(); i++) {
    if (str[i] < str[i - 1]) {
      l = i, r = i + 1;
      char ch = str[i];
      str[i] = str[i - 1];
      str[i - 1] = ch;
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
    cout << l << " " << r << "\n";
  } else
    cout << "NO\n";
  return 0;
}