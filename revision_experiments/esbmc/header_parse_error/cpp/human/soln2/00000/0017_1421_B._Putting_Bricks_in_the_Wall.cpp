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
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    if (a[1][0] == a[0][1] && a[n - 1][n - 2] == a[n - 2][n - 1] &&
        a[1][0] != a[n - 1][n - 2]) {
      cout << 0 << "\n";
    } else if (a[1][0] != a[0][1] && a[n - 1][n - 2] != a[n - 2][n - 1]) {
      cout << 2 << "\n";
      if (a[1][0] == '1') {
        a[0][1] = '1';
        cout << 1 << " " << 2 << "\n";
        if (a[n - 1][n - 2] == '1') {
          a[n - 1][n - 2] = '0';
          cout << n << " " << n - 1 << "\n";
        } else if (a[n - 2][n - 1] == '1') {
          a[n - 2][n - 1] = '0';
          cout << n - 1 << " " << n << "\n";
        }
      } else if (a[1][0] == '0') {
        a[0][1] = '0';
        cout << 1 << " " << 2 << "\n";
        if (a[n - 1][n - 2] == '0') {
          a[n - 1][n - 2] = '1';
          cout << n << " " << n - 1 << "\n";
        } else if (a[n - 2][n - 1] == '0') {
          a[n - 2][n - 1] = '1';
          cout << n - 1 << " " << n << "\n";
        }
      }
    } else if (a[1][0] == a[0][1] && a[n - 1][n - 2] != a[n - 2][n - 1]) {
      cout << 1 << "\n";
      if (a[1][0] == '0') {
        if (a[n - 1][n - 2] == '0') {
          cout << n << " " << n - 1 << "\n";
        } else if (a[n - 2][n - 1] == '0') {
          cout << n - 1 << " " << n << "\n";
        }
      }
      if (a[1][0] == '1') {
        if (a[n - 1][n - 2] == '1') {
          cout << n << " " << n - 1 << "\n";
        } else if (a[n - 2][n - 1] == '1') {
          cout << n - 1 << " " << n << "\n";
        }
      }
    } else if (a[1][0] != a[0][1] && a[n - 1][n - 2] == a[n - 2][n - 1]) {
      cout << 1 << "\n";
      if (a[n - 1][n - 2] == '0') {
        if (a[1][0] == '0') {
          cout << 2 << " " << 1 << "\n";
        } else {
          cout << 1 << " " << 2 << "\n";
        }
      } else {
        if (a[1][0] == '1') {
          cout << 2 << " " << 1 << "\n";
        } else {
          cout << 1 << " " << 2 << "\n";
        }
      }
    } else if (a[1][0] == a[0][1] && a[n - 1][n - 2] == a[n - 2][n - 1] &&
               a[1][0] == a[n - 1][n - 2]) {
      cout << 2 << "\n";
      cout << 1 << " " << 2 << "\n";
      cout << 2 << " " << 1 << "\n";
    }
  }
  return 0;
}