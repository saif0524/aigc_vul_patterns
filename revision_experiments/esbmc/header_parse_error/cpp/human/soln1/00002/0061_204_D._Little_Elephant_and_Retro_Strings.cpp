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
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int N = 1000010;
long long BSum[N + 1], WSum[N + 1];
long long leftmost[N + 1], Bfree[N + 1], rightmost[N + 1], Wfree[N + 1];
string s;
void computeLeft(int n, int k) {
  Bfree[0] = 1LL;
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (i >= k and WSum[i] - WSum[i - k] == 0) {
      if (i == k or s[i - k - 1] != 'B') {
        leftmost[i] = Bfree[max(i - k - 1, 0)];
      }
    }
    long long temp = Bfree[i - 1];
    if (s[i - 1] == 'X') temp = (temp * 2LL) % 1000000007;
    temp = (temp - leftmost[i] + 1000000007) % 1000000007;
    Bfree[i] = temp;
  }
}
void computeRight(int n, int k) {
  Wfree[n] = 1;
  for (int i = (int)(n - 1); i >= (int)(0); --i) {
    if (i <= n - k and BSum[i + k] - BSum[i] == 0) {
      if (i == n - k or s[i + k] != 'W')
        rightmost[i] = Wfree[min(i + k + 1, n)];
    }
    long long temp = Wfree[i + 1];
    if (s[i] == 'X') temp = (temp * 2LL) % 1000000007;
    temp = (temp - rightmost[i] + 1000000007) % 1000000007;
    Wfree[i] = temp;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    BSum[i + 1] = BSum[i] + (s[i] == 'B' ? 1 : 0);
    WSum[i + 1] = WSum[i] + (s[i] == 'W' ? 1 : 0);
  }
  computeLeft(n, k), computeRight(n, k);
  long long answer1 = 0;
  long long twoPow = 1LL;
  for (int i = (int)(n - 1); i >= (int)(0); --i) {
    if (s[i] == 'X') twoPow = (twoPow * 2LL) % 1000000007;
    long long containW = (twoPow - Wfree[i] + 1000000007) % 1000000007;
    answer1 = (answer1 + leftmost[i] * containW) % 1000000007;
  }
  cout << answer1 << "\n";
  return 0;
}