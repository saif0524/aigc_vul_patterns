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
long long int modu(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return ans;
}
int main() {
  ((void)0);
  ((void)0);
  long long int n;
  cin >> n;
  long long int arr[n + 1];
  set<long long int> s;
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
  }
  long long int cn = 0;
  vector<long long int> ans;
  while (s.find(cn) != s.end()) cn++;
  ans.push_back(cn);
  cn++;
  long long int i = 2;
  while (i <= n) {
    if (arr[i] == arr[i - 1]) {
      while (s.find(cn) != s.end()) cn++;
      ans.push_back(cn);
      cn++;
      i++;
    } else {
      ans.push_back(arr[i - 1]);
      i++;
    }
  }
  for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}