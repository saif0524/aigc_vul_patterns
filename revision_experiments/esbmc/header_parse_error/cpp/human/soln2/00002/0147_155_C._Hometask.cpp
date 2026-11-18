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
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
pair<char, char> v[15];
int main() {
  int ans = 0, l;
  string s;
  cin >> s;
  l = (int)(s.size());
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    cin >> v[i].first;
    cin >> v[i].second;
  }
  for (int i = 0; i < k; i++) {
    char a = v[i].first;
    char b = v[i].second;
    char tmp;
    int j = 0;
    while (j < l) {
      if (s[j] == a || s[j] == b) {
        int k = j;
        char c = s[j];
        int cnt = 0;
        while (j < l && (s[j] == a || s[j] == b)) {
          if (s[j] == c) cnt++;
          j++;
        }
        if (j - k != cnt) ans += min(cnt, j - k - cnt);
      } else
        j++;
    }
  }
  printf("%d\n", ans);
  return 0;
}