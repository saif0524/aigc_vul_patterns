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
const int N = 100005;
char a[N];
int main() {
  scanf("%s", a);
  int n = strlen(a);
  int cnt1 = 0, cnt2 = 0;
  int flag1 = 0, flag2 = 0;
  char last = '0';
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    int t = i;
    while (i + 1 < n && a[i] == a[i + 1]) {
      i++;
      cnt++;
    }
    if (cnt % 2 == 0) continue;
    if (a[t] == '+') {
      if (a[t] != last) {
        cnt1++;
        last = a[t];
      } else {
        cnt1--;
        last = '-';
      }
    } else {
      if (a[t] != last) {
        cnt2++;
        last = a[t];
      } else {
        cnt2--;
        last = '+';
      }
    }
  }
  if (cnt1 + cnt2 == 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}