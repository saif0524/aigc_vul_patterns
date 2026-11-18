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
const int MM = 100005;
const long long MOD = 1000000007;
bool judge(int hpy, int atky, int defy, int hpm, int atkm, int defm) {
  int a = max(0, atky - defm), b = max(0, atkm - defy);
  if (a == 0) return false;
  if (b == 0) return true;
  int c = hpm % a == 0 ? hpm / a : hpm / a + 1;
  int d = hpy % b == 0 ? hpy / b : hpy / b + 1;
  if (d > c) return true;
  return false;
}
int main() {
  int h, a, d;
  int hpy, atky, defy, hpm, atkm, defm;
  scanf("%d%d%d", &hpy, &atky, &defy);
  scanf("%d%d%d", &hpm, &atkm, &defm);
  scanf("%d%d%d", &h, &a, &d);
  int ans = (1 << 30);
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      for (int k = 0; k <= 1000; k++) {
        if (i * h + j * a + k * d > ans) break;
        if (judge(hpy + i, atky + j, defy + k, hpm, atkm, defm)) {
          ans = min(ans, i * h + j * a + k * d);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}