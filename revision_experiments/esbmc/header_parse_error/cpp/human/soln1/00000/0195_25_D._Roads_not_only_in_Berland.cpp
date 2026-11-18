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
#pragma comment(linker, "/STACK:25600000")
using namespace std;
const int undef = -1;
int n = 0;
int visited[1000];
vector<list<int> > graph;
vector<int> delegates;
set<pair<int, int> > road_list;
void init() {
  delegates.reserve(1000 + 10);
  graph.reserve(1000 + 10);
  for (int i = 0; i < 1000; ++i) {
    visited[i] = undef;
    graph.push_back(list<int>());
    delegates.push_back(undef);
  }
  cin >> n;
  int a = 0;
  int b = 0;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
}
void explore(int, int, int);
void solve() {
  int comp = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i] == undef) {
      explore(i, comp, undef);
      delegates[comp] = i;
      comp++;
    }
  }
  cout << comp - 1 << endl;
  int i = 0;
  while (comp - 1 != 0) {
    set<pair<int, int> >::iterator sIt = road_list.begin();
    pair<int, int> p = *sIt;
    cout << p.first + 1 << " " << p.second + 1 << " ";
    cout << delegates[i] + 1 << " " << delegates[i + 1] + 1 << endl;
    road_list.erase(sIt);
    ++i;
    --comp;
  }
}
void explore(int i, int component, int comefrom) {
  visited[i] = component;
  for (list<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
    if (visited[*it] == undef) {
      explore(*it, component, i);
    } else if (comefrom != *it) {
      if (road_list.find(make_pair(*it, i)) == road_list.end()) {
        road_list.insert(make_pair(i, *it));
      }
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}