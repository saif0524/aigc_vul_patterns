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
const int N = 1e5 + 4;
const int mod = 1e9 + 7;
int dp[N];
char a[N];
int main() {
  scanf("%s", a + 1);
  int n = strlen(a + 1);
  int sum = 0;
  int ans = 0;
  int flag = 0;
  for (int i = 1; i <= n;) {
    if (a[i] == 'a') {
      dp[i] = sum + 1;
      dp[i] %= mod;
      ans += dp[i];
      ans %= mod;
    } else if (a[i] == 'b') {
      sum += ans;
      sum %= mod;
      ans = 0;
      while (a[i] != 'a' && i <= n) i++;
      i--;
    }
    i++;
  }
  sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = sum + dp[i];
    sum %= mod;
  }
  cout << sum << endl;
}