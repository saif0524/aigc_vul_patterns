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
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, e, i, j, k, l;
    cin >> a;
    vector<long long> v;
    for (i = 1; i <= a; i++) {
      cin >> b;
      if (i == 1)
        l = b;
      else
        l = max(l, b);
      v.push_back(b);
    }
    j = 0;
    for (i = 0; i < a; i++) {
      if (v[i] == l) {
        if (i == 0 && v[i + 1] < v[i]) {
          cout << i + 1 << endl;
          j = 1;
          break;
        } else if (i == a - 1 && v[i] > v[i - 1]) {
          cout << i + 1 << endl;
          j = 1;
          break;
        } else if (i != 0 && i + 1 < a) {
          if (v[i] > v[i + 1]) {
            cout << i + 1 << endl;
            j = 1;
            break;
          }
          if (v[i] > v[i - 1]) {
            cout << i + 1 << endl;
            j = 1;
            break;
          }
        }
      }
    }
    if (j == 0) cout << -1 << endl;
  }
}