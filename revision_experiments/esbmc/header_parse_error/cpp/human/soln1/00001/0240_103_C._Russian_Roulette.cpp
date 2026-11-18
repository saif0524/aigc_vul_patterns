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
  long long n, k, p;
  cin >> n >> k >> p;
  while (p--) {
    long long x;
    cin >> x;
    if (k == 0) {
      cout << '.';
      continue;
    } else {
      if (n % 2) {
        if (x == n)
          cout << 'X';
        else {
          long long num_even = min(k - 1, (n - 1) / 2);
          long long num_odd = (k - 1) - num_even;
          if (x % 2 == 0) {
            long long dist = (n - 1 - x) / 2;
            if (dist + 1 <= num_even) {
              cout << 'X';
            } else {
              cout << '.';
            }
          } else {
            long long dist = (n - 2 - x) / 2;
            if (dist + 1 <= num_odd) {
              cout << 'X';
            } else {
              cout << '.';
            }
          }
        }
      } else {
        long long num_even = min(k, (n) / 2);
        long long num_odd = (k)-num_even;
        if (x % 2 == 0) {
          long long dist = (n - x) / 2;
          if (dist + 1 <= num_even) {
            cout << 'X';
          } else {
            cout << '.';
          }
        } else {
          long long dist = (n - 1 - x) / 2;
          if (dist + 1 <= num_odd) {
            cout << 'X';
          } else {
            cout << '.';
          }
        }
      }
    }
  }
  return 0;
}