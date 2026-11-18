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
struct Frog {
  long long pos, reach;
  int id;
  Frog(long long a, long long b, int c) {
    pos = a;
    reach = b;
    id = c;
  }
  bool operator<(const Frog &other) const { return pos < other.pos; }
};
int n, m, good;
long long tree[800001], eaten[200001], len[200001];
vector<Frog> frogs;
multiset<pair<int, int>> mosquitoes;
int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) {
  if (L == R) {
    tree[p] = frogs[L].reach;
    return;
  }
  int li = left(p);
  int ri = right(p);
  build(li, L, (L + R) / 2);
  build(ri, (L + R) / 2 + 1, R);
  tree[p] = max(tree[li], tree[ri]);
}
void query(int p, int L, int R, long long pos, long long bulk) {
  if (L == R) {
    if (tree[p] >= pos && frogs[L].pos <= pos) {
      good = L;
      tree[p] += bulk;
      int cast = frogs[L].id;
      eaten[cast]++;
      len[cast] += bulk;
    }
    return;
  }
  int li = left(p);
  int ri = right(p);
  if (tree[li] >= pos)
    query(li, L, (L + R) / 2, pos, bulk);
  else
    query(ri, (L + R) / 2 + 1, R, pos, bulk);
  tree[p] = max(tree[li], tree[ri]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    len[i] = y;
    frogs.push_back(Frog(x, x + y, i));
  }
  sort(frogs.begin(), frogs.end());
  build(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    good = -1;
    query(1, 0, n - 1, a, b);
    if (good == -1) {
      mosquitoes.insert(make_pair(a, b));
      continue;
    }
    auto it = mosquitoes.lower_bound(make_pair(frogs[good].pos, 0)), it2 = it;
    while (it != mosquitoes.end()) {
      good = -1;
      query(1, 0, n - 1, (*it).first, (*it).second);
      if (good == -1) break;
      it++;
      mosquitoes.erase(it2);
      it2 = it;
    }
  }
  for (int i = 0; i < n; i++) cout << eaten[i] << " " << len[i] << endl;
  return 0;
}