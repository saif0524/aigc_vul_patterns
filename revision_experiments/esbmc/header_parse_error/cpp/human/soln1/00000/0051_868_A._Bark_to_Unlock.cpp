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
char s[101][3];
int main() {
  int n, i, k = 0, c1 = 0, c2 = 0;
  cin.get(s[0], 3);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin.get();
    cin.get(s[i], 3);
  }
  for (i = 1; i <= n && k < 2; i++) {
    if (s[0][0] == s[i][1] && c1 == 0) {
      k++;
      c1 = 1;
    }
    if (s[0][1] == s[i][0] && c2 == 0) {
      k++;
      c2 = 1;
    }
    if (strcmp(s[0], s[i]) == NULL) k = 2;
  }
  if (k == 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}