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
int que[10000000];
char ss[10000000];
int day[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
int main() {
  int n, m;
  int head = 0, tail = 0;
  int now;
  int ye, mo, da, h, mi, s;
  cin >> n >> m;
  while (scanf("%d-%d-%d %d:%d:%d:", &ye, &mo, &da, &h, &mi, &s) != EOF) {
    gets(ss);
    now = day[mo - 1];
    now = (now + da - 1) * 24 * 60 * 60 + h * 60 * 60 + mi * 60 + s;
    que[tail++] = now;
    while (que[head] <= now - n) head++;
    if (tail - head >= m) {
      printf("2012-%02d-%02d %02d:%02d:%02d\n", mo, da, h, mi, s);
      return 0;
    }
  }
  cout << -1 << endl;
}