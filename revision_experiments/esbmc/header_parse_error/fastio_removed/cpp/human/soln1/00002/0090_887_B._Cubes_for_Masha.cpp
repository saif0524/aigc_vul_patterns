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
int arr[3][15];
int ar[100005];
void solve() {}
int main() {
  ((void)0);
  ((void)0);
  int t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) cin >> arr[i][j];
  }
  if (n == 1) {
    for (int i = 0; i < 6; i++) ar[arr[0][i]]++;
  }
  if (n == 2) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        int p = arr[0][i];
        int q = arr[1][j];
        ar[p] = 1;
        ar[q] = 1;
        ar[p * 10 + q] = 1;
        ar[q * 10 + p] = 1;
      }
    }
  } else {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 6; k++) {
          int p = arr[0][i];
          int q = arr[1][j];
          int r = arr[2][k];
          ar[p] = 1;
          ar[q] = 1;
          ar[r] = 1;
          ar[p * 10 + q] = 1;
          ar[p * 10 + r] = 1;
          ar[q * 10 + p] = 1;
          ar[q * 10 + r] = 1;
          ar[r * 10 + p] = 1;
          ar[r * 10 + q] = 1;
          ar[p * 100 + q * 10 + r]++;
          ar[p * 100 + r * 10 + q]++;
          ar[q * 100 + p * 10 + r]++;
          ar[q * 100 + r * 10 + p]++;
          ar[r * 100 + p * 10 + q]++;
          ar[r * 100 + q * 10 + p]++;
        }
      }
    }
  }
  int c = 0;
  for (int i = 1; i < 10000; i++) {
    if (ar[i] > 0) {
      c = i;
    } else
      break;
  }
  cout << c << endl;
}