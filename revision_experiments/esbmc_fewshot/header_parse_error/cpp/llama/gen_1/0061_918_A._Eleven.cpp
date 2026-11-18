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
  int n;
  cin >> n;
  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);
  while (fib.back() <= n) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
  for (int i = 1; i <= n; i++) {
    bool found = false;
    for (int j = 0; j < fib.size(); j++) {
      if (fib[j] == i) {
        cout << 'O';
        found = true;
        break;
      }
    }
    if (!found) cout << 'o';
  }
  cout << endl;
  return 0;
}