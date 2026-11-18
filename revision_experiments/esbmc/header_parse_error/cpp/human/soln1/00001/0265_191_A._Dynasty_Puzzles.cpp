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
long long dp[26][26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, l = 0, p = 0, i, flag = 0, k, t, d = 0, q = 0, r = 0;
  cin >> n;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long start, last;
    k = (long long)s.size();
    start = s[0] - 'a';
    last = s[k - 1] - 'a';
    for (long long j = 0; j < 26; j++) {
      if (dp[j][start] == 0) continue;
      dp[j][last] = max(dp[j][last], dp[j][start] + k);
    }
    dp[start][last] = max(dp[start][last], k);
  }
  for (long long i = 0; i < 26; i++) {
    p = max(p, dp[i][i]);
  }
  cout << p;
  return 0;
}