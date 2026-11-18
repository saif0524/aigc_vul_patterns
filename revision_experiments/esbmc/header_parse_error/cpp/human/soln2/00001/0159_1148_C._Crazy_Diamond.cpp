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
const int MAX_N = (int)3e5 + 5;
int N, P[MAX_N], loc[MAX_N];
vector<pair<int, int> > ans;
void solve(int x) {
  int idx = loc[x];
  while (x != idx) {
    int idx2 = -1, val = -1;
    if (abs(x - idx) >= N / 2)
      idx2 = x, val = P[x];
    else {
      if (idx < N / 2)
        idx2 = N - 1, val = P[N - 1];
      else
        idx2 = 0, val = P[0];
    }
    ans.emplace_back(pair<int, int>(idx + 1, idx2 + 1));
    swap(P[idx], P[idx2]), swap(loc[x], loc[val]);
    idx = idx2;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P[i], P[i]--;
    loc[P[i]] = i;
  }
  for (int i = 0; i < N / 2; i++) {
    solve(N / 2 - i - 1);
    solve(N / 2 + i);
  }
  printf("%d\n", ans.size());
  for (auto p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}