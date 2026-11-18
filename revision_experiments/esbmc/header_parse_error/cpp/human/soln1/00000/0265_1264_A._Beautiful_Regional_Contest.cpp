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
int p[400100];
int s[400100];
int cnt[1000100], ct[400100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    int len = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[p[i]] == 0 and i > 1) {
        ct[++len] = cnt[p[i - 1]];
        cnt[p[i]]++;
        continue;
      }
      cnt[p[i]]++;
    }
    ct[++len] = cnt[p[n]];
    for (int i = 1; i <= len; i++) s[i] = s[i - 1] + ct[i];
    int id = upper_bound(s + 1, s + len + 1, n / 2) - s - 1;
    int g = ct[1];
    int st = upper_bound(s + 1, s + len + 1, 2 * g) - s;
    int ed = upper_bound(s + 1, s + len + 1, s[st] + g) - s;
    if (ed <= id) {
      printf("%d %d %d\n", g, s[st] - g, s[id] - s[st]);
    } else {
      puts("0 0 0");
    }
    for (int i = 1; i <= n; i++) cnt[p[i]] = 0;
    for (int i = 1; i <= len; i++) s[i] = 0, ct[i] = 0;
  }
  return 0;
}