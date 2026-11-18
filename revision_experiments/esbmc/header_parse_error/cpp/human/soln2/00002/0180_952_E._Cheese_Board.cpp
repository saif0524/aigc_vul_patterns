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
void passe(int i, int &bleu, int &rouge) {
  int a = (i + 1) / 2;
  int b = i / 2;
  bleu = a * a + b * b;
  rouge = a * b + a * b;
}
int main() {
  int n;
  cin >> n;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (b == "soft")
      ++c1;
    else
      ++c2;
  }
  for (int i = 1;; ++i) {
    int bleu, rouge;
    passe(i, bleu, rouge);
    if (bleu >= max(c1, c2) && rouge >= min(c1, c2)) {
      cout << i << "\n";
      return 0;
    }
  }
}