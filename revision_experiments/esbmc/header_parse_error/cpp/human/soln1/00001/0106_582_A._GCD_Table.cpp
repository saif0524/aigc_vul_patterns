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
vector<int> a;
map<int, int> m;
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int val;
      scanf("%d", &val);
      m[-val]++;
    }
  for (auto it = m.begin(); it != m.end(); it++) {
    int cnt = it->second;
    if (cnt == 0) continue;
    int val = -(it->first);
    int divCnt = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] % val == 0) divCnt++;
    int num = 1;
    while (2 * divCnt * num + num * num < cnt) num++;
    for (int i = 0; i < a.size(); i++) {
      int g = gcd(a[i], val);
      m[-g] -= 2 * num;
    }
    for (int i = 0; i < num; i++) {
      a.push_back(val);
    }
  }
  for (int val : a) printf("%d ", val);
  printf("\n");
}