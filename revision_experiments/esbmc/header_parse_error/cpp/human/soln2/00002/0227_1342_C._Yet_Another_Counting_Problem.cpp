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
int T;
long long a, b, q, l, r;
int main() {
  cin >> T;
  while (T--) {
    cin >> a >> b >> q;
    bool tab[a * b];
    long long sum = 0LL;
    long long sus[a * b + 1];
    sus[0] = 0;
    for (int i = 0; i < a * b; i++) {
      tab[i] = ((i % b) % a != (i % a) % b);
      if (tab[i]) sus[i]++;
      sus[i + 1] = sus[i];
      if (tab[i]) sum++;
    }
    long long res;
    while (q--) {
      res = 0;
      cin >> l >> r;
      if (l % (a * b) > 0) res -= sus[l % (a * b) - 1];
      l -= l % (a * b);
      res += sus[r % (a * b)];
      r -= r % (a * b);
      res += sum * ((r - l) / (a * b));
      cout << res << " \n"[q == 0];
    }
  }
  return 0;
}