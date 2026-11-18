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
int online[150001], friend_val[150001];
int main() {
  int i, n, k, q, t, type, val, curr;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  scanf("%d%d%d", &n, &k, &q);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &t);
    friend_val[i] = t;
  }
  for (i = 1; i <= q; ++i) {
    scanf("%d%d", &type, &val);
    if (type == 1) {
      pq.push(pair<int, int>(friend_val[val], val));
      online[val] = 1;
      if ((int)pq.size() - 1 >= k) {
        curr = pq.top().second;
        pq.pop();
        online[curr] = 0;
      }
    } else {
      if (online[val] == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}