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
  string name1, name2, names[10001][2];
  cin >> name1;
  cin >> name2;
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      cin >> names[i][j];
    }
  }
  cout << name1 << " " << name2 << "\n";
  for (i = 0; i < n; i++) {
    if (names[i][0] == name1) {
      name1 = names[i][1];
      cout << name1 << " " << name2 << "\n";
    }
    if (names[i][0] == name2) {
      name2 = names[i][1];
      cout << name1 << " " << name2 << "\n";
    }
  }
  return 0;
}