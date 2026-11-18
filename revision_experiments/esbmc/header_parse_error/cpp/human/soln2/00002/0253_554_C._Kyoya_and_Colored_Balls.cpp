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
vector<pair<long long, pair<long long, long long> > > L;
set<pair<long long, long long> > Z;
struct N {
  int l;
  int d;
};
bool comp(N a, N b) { return a.l < b.l; }
long long combination[1010][1010];
int main() {
  long long k, c, i, j;
  cin >> k;
  combination[0][0] = 1;
  for (i = 1; i < 1004; i++) {
    combination[i][0] = 1;
    for (j = 1; j < i + 1; j++) {
      combination[i][j] =
          (combination[i - 1][j] + combination[i - 1][j - 1]) % 1000000007;
    }
  }
  long long ans = 1, N = 0, R;
  for (i = 0; i < k; i++) {
    cin >> c;
    N += c;
    R = c - 1;
    ans = (ans * combination[N - 1][R]) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}