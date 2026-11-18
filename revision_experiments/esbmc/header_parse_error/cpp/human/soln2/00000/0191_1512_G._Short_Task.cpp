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

const int N = (int) 1e7 + 100;

long long s[N];
int d[N];
int ans[N];

int main() {
  fill(d, d + N, -1);
  d[1] = 1;
  for (int i = 2; i * i < N; i++) {
    if (d[i] == -1) {
      d[i] = i;
      for (int j = i * i; j < N; j += i) {
        if (d[j] == -1) {
          d[j] = i;
        }
      }
    }
  }
  s[1] = 1;
  for (int i = 2; i < N; i++) {
    if (d[i] == -1) {
      d[i] = i;
      s[i] = i + 1;
    } else {
      int j = i;
      s[i] = 1;
      while (j % d[i] == 0) {
        j /= d[i];
        s[i] = s[i] * d[i] + 1;
      }
      s[i] *= s[j];
    }
  }
  fill(ans, ans + N, -1);
  for (int i = N - 1; i > 0; i--) {
    if(s[i]<N){  // avoiding overflow.
    ans[s[i]] = i; 	
	}
      
    
  }
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    int c;
    cin >> c;
    cout << ans[c] << endl;
  }
  return 0;
}