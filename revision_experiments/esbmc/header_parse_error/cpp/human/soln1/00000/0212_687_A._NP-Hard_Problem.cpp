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
vector<vector<int> > p;
vector<int> color;
int count_0, count_1;
int n, m;
bool dfs(int x) {
  int now;
  vector<int> q;
  color[x] = 0;
  count_0++;
  q.push_back(x);
  while (q.size() > 0) {
    now = q.back();
    q.pop_back();
    for (int i = 0; i < p[now].size(); i++) {
      if (color[p[now][i]] > -1) {
        if (color[p[now][i]] != 1 - color[now]) {
          return 1;
        }
      } else {
        color[p[now][i]] = 1 - color[now];
        if (color[p[now][i]])
          count_1++;
        else
          count_0++;
        q.push_back(p[now][i]);
      }
    }
  }
  return 0;
}
int main() {
  int a, b;
  cin >> n >> m;
  p.resize(n);
  color.resize(n, -1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  count_0 = 0;
  count_1 = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == -1 && p[i].size() > 0) {
      if (dfs(i)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  int k = 0;
  cout << count_0 << endl;
  for (int j = 0; j < n; j++) {
    if (color[j] == 0) {
      cout << j + 1;
      k++;
      if (k < count_0)
        cout << " ";
      else
        break;
    }
  }
  cout << endl;
  k = 0;
  cout << count_1 << endl;
  for (int j = 0; j < n; j++) {
    if (color[j] == 1) {
      cout << j + 1;
      k++;
      if (k < count_1)
        cout << " ";
      else
        break;
    }
  }
  cout << endl;
  return 0;
}