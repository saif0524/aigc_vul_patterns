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
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
const int N = 5e5 + 5;
int n;
int positions[26][N];
string names[N];
ll values[N][26];
void dp() {
  for (int idx = n; idx > 0; idx--)
    for (char ch = 'a'; ch <= 'z'; ch++) {
      char last = names[idx].back();
      char first = names[idx][0];
      ll v1 = INT_MIN, v2 = INT_MIN, v3 = INT_MIN;
      if (ch == last) v1 = names[idx].size();
      if (positions[last - 'a'][idx + 1] != n + 1) {
        int pos = positions[last - 'a'][idx + 1];
        v2 = names[idx].size() + values[pos][ch - 'a'];
      }
      if (positions[first - 'a'][idx + 1] != n + 1) {
        int pos = positions[first - 'a'][idx + 1];
        v3 = values[pos][ch - 'a'];
      }
      values[idx][ch - 'a'] = max({v1, v2, v3});
    }
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cout << fixed;
  cout << setprecision(10);
  for (int i = 1; i <= 500000; i++)
    for (int j = 0; j < 26; j++) values[i][j] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> names[i];
  for (int i = 1; i <= n; i++) positions[names[i][0] - 'a'][i] = 1;
  for (int i = 0; i < 26; i++) {
    positions[i][n + 1] = n + 1;
    for (int j = n; j > 0; j--)
      if (positions[i][j])
        positions[i][j] = j;
      else
        positions[i][j] = positions[i][j + 1];
  }
  dp();
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, values[i][names[i][0] - 'a']);
  cout << ans;
}