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
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
int A[N];
int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<int> sol(n + 1);
  for (int i = 0; i < n; i++) {
    vector<int> cnt(n + 1);
    pair<int, int> ans = make_pair(0, 0);
    for (int j = i; j < n; j++) {
      cnt[A[j]]++;
      if (cnt[A[j]] > ans.first) {
        ans = make_pair(cnt[A[j]], A[j]);
      } else if (cnt[A[j]] == ans.first && A[j] < ans.second) {
        ans = make_pair(cnt[A[j]], A[j]);
      }
      sol[ans.second]++;
    }
  }
  for (int i = 1; i <= n; i++) cout << sol[i] << ' ';
  cout << '\n';
  return 0;
}