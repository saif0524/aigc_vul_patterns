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
const int N = 100100;
int n, m, k, p[N], niv[N], sol, tata;
vector<int> v[N];
void dfs(int nod) {
  if (sol) return;
  for (vector<int>::iterator it = v[nod].begin(); it != v[nod].end(); ++it)
    if (p[nod] != *it) {
      if (!p[*it]) {
        p[*it] = nod;
        niv[*it] = niv[nod] + 1;
        dfs(*it);
      } else {
        if (niv[nod] - niv[*it] >= k) {
          sol = nod;
          tata = *it;
          return;
        }
      }
    }
}
int main() {
  int i, a, b;
  cin >> n >> m >> k;
  for (i = 1; i <= m; ++i) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  p[1] = -1;
  dfs(1);
  cout << niv[sol] - niv[tata] + 1 << "\n";
  while (sol != tata) {
    cout << sol << " ";
    sol = p[sol];
  }
  cout << sol << "\n";
  return 0;
}