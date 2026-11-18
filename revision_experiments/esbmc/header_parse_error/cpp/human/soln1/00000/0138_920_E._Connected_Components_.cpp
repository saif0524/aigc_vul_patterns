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
const int N = 2e5 + 5;
set<int> g[N], disconn;
vector<int> ans_vec, temp, temper;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x, y;
  while (m--) {
    cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    v.push_back(i);
  }
  set<int>::iterator it;
  for (it = g[1].begin(); it != g[1].end(); it++) {
    disconn.insert(*it);
  }
  int sz = n;
  while (!v.empty()) {
    for (int i = 0; i < v.size() && !disconn.empty(); i++) {
      x = v[i];
      if (disconn.find(x) != disconn.end()) {
        continue;
      } else {
        for (it = disconn.begin(); it != disconn.end(); it++) {
          if (g[x].find(*it) == g[x].end()) {
            temp.push_back(*it);
          }
        }
        for (int j = 0; j < temp.size(); j++) {
          disconn.erase(temp[j]);
        }
      }
    }
    for (int i = 0; i < temp.size(); i++) {
      x = temp[i];
      for (it = disconn.begin(); it != disconn.end(); it++) {
        if (g[x].find(*it) == g[x].end()) {
          temper.push_back(*it);
        }
      }
      for (int j = 0; j < temper.size(); j++) {
        disconn.erase(temper[j]);
      }
      if (i == temp.size() - 1) {
        temp.clear();
        for (int j = 0; j < temper.size(); j++) {
          temp.push_back(temper[j]);
        }
        if (!temp.empty()) {
          i = -1;
        }
        temper.clear();
      }
    }
    ans_vec.push_back(sz - disconn.size());
    sz = disconn.size();
    v.clear();
    for (it = disconn.begin(); it != disconn.end(); it++) {
      v.push_back(*it);
    }
    it = disconn.begin();
    disconn.erase(*it);
  }
  sort(ans_vec.begin(), ans_vec.end());
  cout << ans_vec.size() << "\n";
  for (int i = 0; i < ans_vec.size(); i++) {
    cout << ans_vec[i] << " ";
  }
  return 0;
}