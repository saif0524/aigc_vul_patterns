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
int d[500000];
vector<int> v[500000];
bool b[500000];
queue<int> q;
int n;
string aa, bb;
void bfs() {
  while (!q.empty()) {
    int x = d[q.front()];
    int y = q.front();
    b[q.front()] = true;
    q.pop();
    for (int i = 0; i < (int)v[y].size(); i++) {
      int a = v[y][i];
      if (!b[a] && a % n > x) {
        d[a] = x + 1;
        b[a] = true;
        q.push(a);
      }
    }
  }
}
int main() {
  int k;
  cin >> n >> k;
  cin >> aa >> bb;
  for (int i = 0; i < n; i++) {
    if ((i + 1 < n && aa[i + 1] != 'X')) {
      v[i].push_back(i + 1);
    }
    if (i + k < n && bb[i + k] != 'X') {
      v[i].push_back(i + k + n);
    }
    if ((i + 1 + n < 2 * n && bb[i + 1] != 'X')) {
      v[i + n].push_back(i + 1 + n);
    }
    if ((i + k + n < 2 * n && aa[i + k] != 'X')) {
      v[i + n].push_back(i + k);
    }
    if (i - 1 >= 0 && aa[i - 1] != 'X') {
      v[i].push_back(i - 1);
    }
    if (i + n - 1 >= n && bb[i - 1] != 'X') {
      v[i + n].push_back(i + n - 1);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    d[i] = 500000;
    b[i] = false;
  }
  d[0] = 0;
  q.push(0);
  bfs();
  int s = 500000;
  for (int i = 0; i < k; i++) {
    s = min(s, d[n - i - 1]);
    s = min(s, d[2 * n - i - 1]);
  }
  if (s == 500000) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}