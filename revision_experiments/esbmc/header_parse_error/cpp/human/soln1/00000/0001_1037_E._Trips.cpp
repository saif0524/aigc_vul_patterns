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
const int module = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> to(n, set<int>());
  vector<pair<int, int>> edges(m);
  vector<int> nbr(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    nbr[a]++;
    nbr[b]++;
    to[a].insert(b);
    to[b].insert(a);
    edges[i] = {a, b};
  }
  vector<bool> vis(n);
  int all = n;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      if (nbr[i] < k) {
        queue<int> q;
        q.push(i);
        vis[i] = true;
        all--;
        while (!q.empty()) {
          int cur = q.front();
          q.pop();
          for (int t : to[cur]) {
            nbr[t]--;
            to[t].erase(cur);
            if (nbr[t] < k && !vis[t]) {
              q.push(t);
              vis[t] = true;
              all--;
            }
          }
        }
      }
    }
  }
  queue<int> q;
  vector<int> answer;
  answer.push_back(all);
  for (int i = m - 1; i > 0; i--) {
    auto [a, b] = edges[i];
    if (!vis[a] && !vis[b]) {
      to[a].erase(b);
      to[b].erase(a);
      nbr[a]--;
      nbr[b]--;
      if (nbr[a] < k) {
        q.push(a);
        vis[a] = true;
        all--;
      }
      if (nbr[b] < k) {
        q.push(b);
        vis[b] = true;
        all--;
      }
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int t : to[cur]) {
          nbr[t]--;
          to[t].erase(cur);
          if (nbr[t] < k && !vis[t]) {
            q.push(t);
            vis[t] = true;
            all--;
          }
        }
      }
    }
    answer.push_back(all);
  }
  for (int i = answer.size() - 1; i >= 0; i--) {
    cout << answer[i] << "\n";
  }
}