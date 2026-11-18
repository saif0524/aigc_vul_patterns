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
long long a, b, c, d, n, m, k, q, l, r;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> l >> r;
  a = r - l;
  if (r - l < 100) {
    map<long long, long long> mp;
    map<long long, long long>::iterator it;
    for (int i = l; i <= r; i++) {
      a = i;
      for (int x = 2; x * x <= a; x++) {
        if (a % x == 0) {
          mp[a / x]++;
          mp[x]++;
        }
      }
      if (a > 1) {
        mp[a]++;
      }
    }
    for (it = mp.begin(); it != mp.end(); it++) {
      b = max(b, it->second);
    }
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second == b) {
        cout << it->first;
        return 0;
      }
    }
  } else {
    cout << 2;
  }
}