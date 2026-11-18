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
int n, m;
int a, b;
int D[100010];
int vis[100010];
vector<int> E[100010];
priority_queue<int> Q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    D[a]++;
    E[b].push_back(a);
  }
  for (int i = n; i >= 1; i--)
    if (D[i] == 0) Q.push(i);
  int now = n;
  while (!Q.empty()) {
    int nd = Q.top();
    Q.pop();
    if (vis[nd]) continue;
    vis[nd] = now--;
    for (auto i : E[nd]) {
      D[i]--;
      if (!D[i] && !vis[i]) Q.push(i);
    }
  }
  for (int i = 1; i <= n; i++) cout << vis[i] << " ";
}