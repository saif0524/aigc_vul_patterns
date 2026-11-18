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

const int N = 150005;
const int M = 31625;

int n;
int a[N], b[N];
int p[M], cnt;
bool np[M];

void init() {
  for (int i = 2; i < M; i++) {
    if (!np[i]) {
      p[cnt++] = i;
      for (int j = i + i; j < M; j += i) {
        np[j] = true;
      }
    }
  }
}

int main() {
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < cnt; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (a[j] % p[i] != 0 && b[j] % p[i] != 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << p[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}