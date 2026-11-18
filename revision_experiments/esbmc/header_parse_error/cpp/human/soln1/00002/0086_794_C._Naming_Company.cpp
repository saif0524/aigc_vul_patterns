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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string first, second;
  cin >> first >> second;
  multiset<char> X, Y;
  for (char ch : first) {
    X.insert(ch);
  }
  for (char ch : second) {
    Y.insert(ch);
  }
  int n = ((int)(first).size());
  int half = n / 2 + (n & 1);
  while (((int)(X).size()) != half) {
    X.erase((--(X.end())));
  }
  while (((int)(Y).size()) != n - half) {
    Y.erase(Y.begin());
  }
  vector<char> ans(n);
  int left = 0, right = n - 1;
  int turn = 1;
  for (int i = 0; i < n; i++) {
    if (turn) {
      if (Y.empty()) {
        ans[left] = *X.begin();
        break;
      }
      char mx = *(--(Y.end()));
      char mn = *X.begin();
      if (mx > mn) {
        ans[left++] = mn;
        X.erase(X.begin());
      } else {
        mx = *(--(X.end()));
        ans[right--] = mx;
        X.erase(X.lower_bound(mx));
      }
    } else {
      char mx = *(--(Y.end()));
      if (X.empty()) {
        ans[left] = mx;
        break;
      }
      char mn = *X.begin();
      if (mx > mn) {
        ans[left++] = mx;
        Y.erase(Y.lower_bound(mx));
      } else {
        mn = *Y.begin();
        ans[right--] = mn;
        Y.erase(Y.begin());
      }
    }
    turn ^= 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << "\n";
}