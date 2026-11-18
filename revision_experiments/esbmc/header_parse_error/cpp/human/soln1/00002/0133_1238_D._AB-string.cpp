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
int n;
string s;
bool f = false;
bool l = false;
long long res = 0;
int main() {
  scanf("%d", &n);
  cin >> s;
  res = (long long)n * (n - 1) / 2;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    int j = i + 1;
    int br = 0;
    while (j < n && s[j] != c) {
      br++;
      j++;
    }
    res -= br;
    br = 0;
    j = i - 1;
    while (j >= 0 && s[j] != c) {
      br++;
      j--;
    }
    if (br != 0) {
      br--;
    }
    res -= br;
  }
  cout << res;
  return 0;
}