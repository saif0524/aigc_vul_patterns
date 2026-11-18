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
vector<string> seqs(string s, string v) {
  auto_ptr<stringstream> sst;
  vector<string> ret;
  for (int i = 0; i < s.size(); i++) {
    if (sst.get() == NULL) {
      if (s[i] == v[0] || s[i] == v[1]) {
        sst.reset(new stringstream());
        *sst.get() << s[i];
      }
    } else {
      if (s[i] == v[0] || s[i] == v[1]) {
        *sst.get() << s[i];
      } else {
        ret.push_back(sst->str());
        sst.release();
      }
    }
  }
  if (sst.get() != NULL) {
    ret.push_back(sst->str());
  }
  return ret;
}
int count(string s, string t) {
  int ret[2] = {0, 0};
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[0])
      ret[0]++;
    else
      ret[1]++;
  }
  return min(ret[0], ret[1]);
}
int main(int argc, char *argv[]) {
  string str;
  int n;
  cin >> str >> n;
  vector<string> v(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    vector<string> w = seqs(str, v[i]);
    for (int j = 0; j < w.size(); j++) {
      ret += count(w[j], v[i]);
    }
  }
  cout << ret << endl;
  return 0;
}