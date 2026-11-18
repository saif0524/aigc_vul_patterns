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
const int Maxn = 100 * 1000 + 10;
int n, inda[Maxn], indb[Maxn];
set<pair<int, int> > a, b, b1;
int main() {
  scanf("%d", &n);
  int aa;
  for (int i = 0; i < n; i++) {
    scanf("%d", &aa);
    aa--;
    inda[aa] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &aa);
    aa--;
    indb[aa] = i;
  }
  for (int i = 0; i < n; i++) {
    if (indb[i] > inda[i])
      a.insert(make_pair(indb[i] - inda[i], inda[i]));
    else
      b.insert(make_pair(inda[i] - indb[i], indb[i])),
          b1.insert(make_pair(indb[i], inda[i] - indb[i]));
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n",
           min((b.begin()->first + i) % n, (a.begin()->first - i + n) % n));
    if (b1.begin()->first == i) {
      int ind = b1.begin()->second + i;
      a.insert(make_pair(n - ind + i, ind));
      b.erase(make_pair(b1.begin()->second, b1.begin()->first));
      b1.erase(b1.begin());
    }
    while (!a.empty() && a.begin()->first == i + 1) {
      b.insert(make_pair(-i - 1, a.begin()->second + i + 1));
      b1.insert(make_pair(a.begin()->second + i + 1, -i - 1));
      a.erase(a.begin());
    }
  }
  return 0;
}