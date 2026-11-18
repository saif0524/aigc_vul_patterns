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
  string message, word, original;
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> word;
    original += "<3";
    original += word;
  }
  original += "<3";
  cin >> message;
  int j = 0;
  string tmp;
  for (int i = 0; i < (int)message.size(); i++) {
    if (j == (int)original.size()) {
      break;
    }
    if (message[i] == original[j]) {
      tmp += message[i];
      j++;
    }
  }
  if (tmp == original) {
    cout << "yes";
    return 0;
  }
  cout << "no";
  return 0;
}