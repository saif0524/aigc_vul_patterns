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
const int MAX = (2e5) + 10;
pair<int, int> ara[MAX];
int id[MAX];
vector<int> didi[MAX];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> ara[i].first;
  }
  for (int i = 0; i <= n - 1; i++) {
    cin >> ara[i].second;
  }
  sort(ara, ara + n, [](pair<int, int> x, pair<int, int> y) {
    return (x.first == y.first) ? x.second > y.second : x.first < y.first;
  });
  int cp = -1;
  priority_queue<int> que;
  long long sum, prin;
  sum = prin = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (cp >= ara[i].first) {
      que.push(ara[i].second);
      sum += ara[i].second;
    } else {
      if (!que.empty()) {
        sum -= que.top();
        que.pop();
        prin += sum;
        cp++;
        i--;
      } else {
        cp = ara[i].first;
        i--;
      }
    }
  }
  while (!que.empty()) {
    sum -= que.top();
    que.pop();
    prin += sum;
  }
  cout << prin << endl;
}
int main() {
  ((void)0);
  int tc;
  solve();
  return 0;
}