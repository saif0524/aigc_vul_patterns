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
long long int i, j, n;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int a1[100] = {0}, b1[100] = {0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a1[a[i]]++;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    b1[b[i]]++;
  }
  int l = 0, m = 0;
  for (i = 1; i <= 5; i++) {
    if (a1[i] > b1[i]) {
      if ((a1[i] - b1[i]) % 2 != 0) {
        cout << "-1";
        return 0;
      }
      l += (a1[i] - b1[i]) / 2;
    } else if (a1[i] < b1[i]) {
      if ((b1[i] - a1[i]) % 2 != 0) {
        cout << "-1";
        return 0;
      }
      m += (b1[i] - a1[i]) / 2;
    }
  }
  cout << m;
  return 0;
}