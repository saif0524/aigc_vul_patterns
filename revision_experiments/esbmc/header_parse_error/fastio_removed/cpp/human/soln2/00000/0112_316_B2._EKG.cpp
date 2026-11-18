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
int Length[1001], n, x, a[1001], Concern, Pos, Ppl;
vector<int> Queues, adj[1001], Ans;
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) adj[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      Ppl = i;
      int len = 0;
      while (Ppl) {
        ++len;
        if (Ppl == x) Concern = i, Pos = len;
        if ((int)adj[Ppl].size())
          Ppl = adj[Ppl][0];
        else
          Ppl = 0;
      }
      if (Concern != i) Queues.push_back(len);
    }
  }
  for (int i = Queues.size() - 1; i >= 0; --i) {
    vector<int> Add;
    for (int j = 0; j < Ans.size(); ++j) {
      if (!Length[Ans[j] + Queues[i]])
        Add.push_back(Ans[j] + Queues[i]), Length[Ans[j] + Queues[i]] = 1;
    }
    for (int j = 0; j < Add.size(); ++j) Ans.push_back(Add[j]);
    if (!Length[Queues[i]]) Ans.push_back(Queues[i]), Length[Queues[i]] = 1;
  }
  cout << Pos << "\n";
  sort(Ans.begin(), Ans.end());
  for (int i = 0; i < Ans.size(); ++i) cout << Pos + Ans[i] << "\n";
  return 0;
}