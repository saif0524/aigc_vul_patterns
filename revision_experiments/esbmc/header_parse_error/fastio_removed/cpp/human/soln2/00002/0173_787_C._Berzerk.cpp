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
const int mod = 1e9 + 7;
const int maxn = 7008;
long long int ans[2][maxn], arr[2][maxn], cnt[2][maxn];
int main() {
  ((void)0);
  long long int n, k[2], i;
  cin >> n;
  cin >> k[0];
  for (i = 0; i < k[0]; i++) cin >> arr[0][i];
  cin >> k[1];
  for (i = 0; i < k[1]; i++) cin >> arr[1][i];
  ans[1][0] = ans[0][0] = 2;
  queue<pair<long long int, long long int> > q;
  q.push(make_pair(1, 0));
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    long long int player = q.front().first, position = q.front().second;
    q.pop();
    if (ans[player][position] == 2) {
      for (i = 0; i < k[1 ^ player]; i++) {
        long long int newPosition = (position - arr[1 ^ player][i] + n) % n;
        if (!ans[1 ^ player][newPosition]) {
          ans[1 ^ player][newPosition] = 1;
          q.push(make_pair(1 ^ player, newPosition));
        }
      }
    } else {
      for (i = 0; i < k[1 ^ player]; i++) {
        long long int newPosition = (position - arr[1 ^ player][i] + n) % n;
        if (!ans[1 ^ player][newPosition]) cnt[1 ^ player][newPosition]++;
        if (!ans[1 ^ player][newPosition] &&
            cnt[1 ^ player][newPosition] == k[1 ^ player]) {
          ans[1 ^ player][newPosition] = 2;
          q.push(make_pair(1 ^ player, newPosition));
        }
      }
    }
  }
  for (i = 1; i < n; i++) {
    if (ans[0][i] == 2)
      cout << "Lose ";
    else if (ans[0][i] == 1)
      cout << "Win ";
    else
      cout << "Loop ";
  }
  cout << endl;
  for (i = 1; i < n; i++) {
    if (ans[1][i] == 2)
      cout << "Lose ";
    else if (ans[1][i] == 1)
      cout << "Win ";
    else
      cout << "Loop ";
  }
  return 0;
}