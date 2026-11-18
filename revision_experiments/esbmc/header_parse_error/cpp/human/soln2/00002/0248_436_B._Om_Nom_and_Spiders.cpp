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
char mapa[2005][2005];
int C[2005];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> mapa[i];
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] == '.') continue;
      if (mapa[i][j] == 'D') continue;
      if (mapa[i][j] == 'U') {
        if (i % 2 == 0) C[j]++;
        continue;
      }
      int pos = j;
      if (mapa[i][j] == 'R')
        pos += i;
      else
        pos -= i;
      if (pos < 0 || pos >= m) continue;
      C[pos]++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (i) cout << " ";
    cout << C[i];
  }
  cout << endl;
  return 0;
}