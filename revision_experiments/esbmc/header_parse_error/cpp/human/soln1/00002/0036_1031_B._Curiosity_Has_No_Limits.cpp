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
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  for (int t = 0; t < 4; t++) {
    vector<int> ans;
    ans.push_back(t);
    for (int i = 1; i < n; i++) {
      for (int x = 0; x < 4; x++)
        if ((ans.back() & x) == b[i - 1] && (ans.back() | x) == a[i - 1]) {
          ans.push_back(x);
          break;
        }
      if (ans.size() == i) break;
    }
    if (ans.size() == n) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << ans[i] << ' ';
      return 0;
    }
  }
  cout << "NO";
}