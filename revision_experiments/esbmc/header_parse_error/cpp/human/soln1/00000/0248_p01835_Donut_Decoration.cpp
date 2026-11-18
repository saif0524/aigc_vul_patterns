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

struct SegmentTree
{
  vector< pair< int, int > > seg;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, make_pair(0, 0));
  }

  void push(int k)
  {
    if(k >= sz - 1 || seg[k] == make_pair(0, 0)) return;
    if(seg[2 * k + 1] == make_pair(0, 0)) {
      seg[2 * k + 1] = seg[k];
    } else if(seg[k].first == seg[2 * k + 1].second) {
      seg[2 * k + 1].second = seg[k].second;
    } else {
      seg[2 * k + 1] = {-1, -1};
    }
    if(seg[2 * k + 2] == make_pair(0, 0)) {
      seg[2 * k + 2] = seg[k];
    } else if(seg[k].first == seg[2 * k + 2].second) {
      seg[2 * k + 2].second = seg[k].second;
    } else {
      seg[2 * k + 2] = {-1, -1};
    }
    seg[k] = {0, 0};
  }

  void update(int a, int b, int x, int k, int l, int r)
  {
    push(k);
    if(a >= r || b <= l) {

    } else if(a <= l && r <= b) {
      if(seg[k] == make_pair(-1, -1)) return;
      if(k >= sz - 1) {
        if(seg[k].second == x) seg[k].second++;
        else seg[k] = {-1, -1};
      } else {
        seg[k] = {x, x + 1};
      }
      push(k);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) >> 1);
      update(a, b, x, 2 * k + 2, (l + r) >> 1, r);
    }
  }

  void update(int a, int b, int x)
  {
    update(a, b, x, 0, 0, sz);
  }

  int query(int a, int b, int x, int k, int l, int r)
  {
    push(k);
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) {
      return (seg[k] == make_pair(0, x));
    }
    return (query(a, b, x, 2 * k + 1, l, (l + r) >> 1) +
            query(a, b, x, 2 * k + 2, (l + r) >> 1, r));
  }

  int query(int a, int b, int x)
  {
    return (query(a, b, x, 0, 0, sz));
  }

};

int main()
{

  int N, K, T;
  scanf("%d %d", &N, &K);
  scanf("%d", &T);
  SegmentTree tree(N);
  while(T--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    tree.update(--l, r, --x);
  }
  int ret = 0;
  for(int i = 0; i < N; i++) ret += tree.query(i, i + 1, K);
  printf("%d\n", ret);
}