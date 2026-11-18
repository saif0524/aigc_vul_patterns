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
const int MAX_N = 500 + 10;
int Arr[MAX_N];
map<int, int> m;
int n;
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  return (b == 0 ? a : gcd(b, a % b));
}
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int temp;
    cin >> temp;
    m[temp]++;
  }
  for (int i = 0; i < n; i++) {
    map<int, int>::reverse_iterator it = m.rbegin();
    while (it->second <= 0) {
      m.erase(it->first);
      it = m.rbegin();
    }
    int key = (it->first);
    m[key]--;
    Arr[i] = key;
    for (int j = 0; j < i; j++) m[gcd(key, Arr[j])]--, m[gcd(Arr[j], key)]--;
  }
  for (int i = 0; i < n; i++) cout << Arr[i] << " ";
  cout << endl;
  return 0;
}