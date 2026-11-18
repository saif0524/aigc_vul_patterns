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
long int sum[1001][1001], size1[1001];
vector<long int> ar;
int main() {
  long int n, i, j, k, a, sum1 = 0, sum2 = 0, temp;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    size1[i] = k;
    for (j = 0; j < k; j++) {
      cin >> a;
      if (j) {
        sum[i][j] = sum[i][j - 1] + a;
      } else {
        sum[i][j] = a;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (size1[i] % 2 == 0) {
      temp = size1[i] / 2;
      sum1 += sum[i][temp - 1];
      sum2 += sum[i][size1[i] - 1] - sum[i][temp - 1];
    } else {
      temp = size1[i] / 2;
      if (temp != 0) {
        sum1 += sum[i][temp - 1];
      }
      sum2 += sum[i][size1[i] - 1] - sum[i][temp];
      ar.push_back(sum[i][temp] - sum[i][temp - 1]);
    }
  }
  sort(ar.begin(), ar.end());
  reverse(ar.begin(), ar.end());
  for (i = 0; i < ar.size(); i++) {
    if (i % 2) {
      sum2 += ar[i];
    } else {
      sum1 += ar[i];
    }
  }
  cout << sum1 << " " << sum2;
  return 0;
}