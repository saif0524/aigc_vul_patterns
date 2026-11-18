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
int n;
int lista[10001];
int d1, d2;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> lista[i];
  int min = 1;
  int max = n;
  int vez = 0;
  for (int i = 1; i <= n; i++) {
    if (vez % 2 == 0) {
      if (lista[max] > lista[min]) {
        d1 += lista[max];
        max--;
      } else {
        d1 += lista[min];
        min++;
      }
      vez++;
    } else {
      if (lista[max] > lista[min]) {
        d2 += lista[max];
        max--;
      } else {
        d2 += lista[min];
        min++;
      }
      vez++;
    }
  }
  cout << d1 << " " << d2;
}
int main() { solve(); }