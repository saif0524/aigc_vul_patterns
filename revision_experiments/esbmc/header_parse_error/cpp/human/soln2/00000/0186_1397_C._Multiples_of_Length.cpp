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
int N;
int arr[101010];
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  if (N == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << -arr[0] << endl;
  } else {
    cout << 1 << " " << N << endl;
    for (int i = 0; i < N; ++i) cout << -1LL * arr[i] * N << " ";
    cout << endl;
    cout << 1 << " " << N - 1 << endl;
    for (int i = 0; i < N - 1; ++i) cout << 1LL * arr[i] * (N - 1) << " ";
    cout << endl;
    cout << N << " " << N << endl;
    cout << 1LL * arr[N - 1] * (N - 1) << " ";
    cout << endl;
  }
}