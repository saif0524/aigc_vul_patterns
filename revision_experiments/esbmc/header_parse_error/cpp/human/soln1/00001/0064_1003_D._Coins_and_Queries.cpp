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
  int n, q;
  map<int, int> coins;
  cin >> n >> q;
  int queries[q];
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    coins[val]++;
  }
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }
  for (int i = 0; i < q; i++) {
    int counter = 0;
    int curr = 0;
    for (auto it = coins.rbegin(); it != coins.rend(); it++) {
      int num = min(it->second, (queries[i] - curr) / (it->first));
      counter += num;
      curr += num * (it->first);
    }
    if (curr == queries[i]) {
      cout << counter << endl;
    } else {
      cout << -1 << endl;
    }
  }
}