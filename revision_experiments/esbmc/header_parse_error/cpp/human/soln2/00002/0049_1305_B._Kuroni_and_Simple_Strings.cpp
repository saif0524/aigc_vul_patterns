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
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int exp(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, i, j;
  string s;
  cin >> s;
  vector<long long int> ans;
  n = s.size();
  j = n - 1;
  for (i = 0; i < j; i++) {
    while (j > i && s[i] == '(') {
      if (s[i] == '(' && s[j] == ')') {
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        j--;
        break;
      }
      j--;
    }
  }
  if (ans.size() == 0)
    cout << 0;
  else {
    sort(ans.begin(), ans.end());
    cout << 1 << '\n';
    cout << ans.size() << endl;
    for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  return 0;
}