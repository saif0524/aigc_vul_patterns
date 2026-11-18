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

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;

int N, M, suf, pref;
vector<int> add[maxn];

signed main(void)
{
  ((void)0); ((void)0); ((void)0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N >> M;
  for(int i = 1; i <= N; ++i){
    int l, r; cin >> l >> r;
    add[l].eb(r);
  }
  priority_queue<int> pq;
  for(int i = M; i >= 1; --i){
    for(int j : add[i])
      pq.push(j);
    if(pq.size()){
      pq.pop();
      ++pref;
    }
  }
  for(int i : add[0]) pq.push(i);
  int ans = pref; suf = M;
  while(pq.size()){
    int now = pq.top(); pq.pop();
    if(now <= suf && suf > pref){
      ++ans;
      --suf;
    }
  }
  cout << N - ans;
}