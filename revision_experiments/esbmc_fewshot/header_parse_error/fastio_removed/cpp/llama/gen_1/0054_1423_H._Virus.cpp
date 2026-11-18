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

const int N = 1e5 + 5;

int n, q, k;
vector<pair<int, int>> events[N];
int day = 0;

struct UnionFind {
  vector<int> parent, size;

  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
    }
  }

  int getSize(int x) {
    return size[find(x)];
  }
};

int main() {
  ((void)0);
  ((void)0);

  cin >> n >> q >> k;

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      events[day].emplace_back(x, y);
    } else if (t == 2) {
      int x;
      cin >> x;
      x--;
      UnionFind uf(n);
      for (int j = max(0, day - k + 1); j <= day; j++) {
        for (auto& event : events[j]) {
          uf.unite(event.first, event.second);
        }
      }
      cout << uf.getSize(x) << '\n';
    } else {
      day++;
    }
  }

  return 0;
}