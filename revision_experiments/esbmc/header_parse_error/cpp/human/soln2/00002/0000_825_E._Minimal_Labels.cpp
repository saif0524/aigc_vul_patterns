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
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > parents(n);
  int deg[n];
  fill(deg, deg + n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    parents[b - 1].push_back(a - 1);
    deg[a - 1]++;
  }
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) q.push(i);
  }
  int rank[n];
  for (int i = n; i >= 1; i--) {
    int x = q.top();
    q.pop();
    for (int j = 0; j < parents[x].size(); j++) {
      deg[parents[x][j]]--;
      if (deg[parents[x][j]] == 0) q.push(parents[x][j]);
    }
    rank[x] = i;
  }
  for (int i = 0; i < n; i++) {
    cout << rank[i] << " ";
  }
  cout << endl;
}