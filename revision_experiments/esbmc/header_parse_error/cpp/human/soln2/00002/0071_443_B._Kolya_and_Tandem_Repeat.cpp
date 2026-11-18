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
long long n, m, k;
vector<vector<pair<int, int> > > v2;
long long costs[(int)1e5 + 5];
int parent[(int)1e5 + 5];
vector<int> answer;
void dikstra() {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  pq.push({0, 1});
  parent[1] = -1;
  costs[1] = 0;
  while (!pq.empty()) {
    int node = pq.top().second;
    long long cost = pq.top().first;
    pq.pop();
    for (auto I : v2[node]) {
      if (costs[I.second] > cost + I.first) {
        costs[I.second] = cost + I.first;
        parent[I.second] = node;
        pq.push({costs[I.second], I.second});
      }
    }
  }
}
int main() {
  string s;
  cin >> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    s.push_back('!');
  }
  int mx = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      int l = 0;
      for (int k = i; k < i + ((j - i + 1) / 2); k++) {
        if (s[k] == '!' || s[k + (j - i + 1) / 2] == '!') {
          l++;
        } else if (s[k] == s[k + (j - i + 1) / 2]) {
          l++;
        } else
          break;
      }
      mx = max(mx, l * 2);
    }
  }
  cout << mx << endl;
}