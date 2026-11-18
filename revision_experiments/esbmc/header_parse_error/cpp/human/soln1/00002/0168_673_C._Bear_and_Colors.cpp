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
int t[5005], n, used[5005], ret[5005];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    memset(used, 0, sizeof used);
    used[t[i]]++;
    int mx = t[i];
    ret[t[i]]++;
    for (int j = i + 1; j < n; ++j) {
      used[t[j]]++;
      if (used[t[j]] > used[mx] || (used[t[j]] == used[mx] && t[j] < mx))
        mx = t[j];
      ret[mx]++;
    }
  }
  for (int i = 1; i <= n; ++i) cout << ret[i] << " ";
  return 0;
}