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
int main() {
  long long int i, c = 0, n, T, cs = 0, k, x, j;
  T = 1;
  string s = "";
  while (T--) {
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    i = n - 1;
    j = 0;
    c = 0;
    while (i >= j) {
      if (a[i] == a[j] && i != j) {
        k = j, cs = c;
        string p = "", q = "";
        while (j < i && a[j] > c) p += 'L', c = a[j], j++;
        c = cs;
        while (i > k && a[i] > c) q += 'R', c = a[i], i--;
        if (p.size() > q.size())
          s += p;
        else
          s += q;
        break;
      } else if (a[i] > a[j] && a[j] > c)
        s += 'L', c = a[j], j++;
      else if (a[i] > c)
        s += 'R', c = a[i], i--;
      else if (a[j] > c)
        s += 'L', c = a[j], j++;
      else
        break;
    }
    cout << s.size() << "\n" << s;
  }
  return 0;
}