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


#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<int> g[125252];

bool used[125252];
stack<int> hist;
int po = -1;

bool namo[125252];

void dfs(int p, int bef){
  if(used[p]){
    po = p;
    return;
  }
  used[p] = true;
  hist.push(p);
  for(int to : g[p])if(to != bef){
    dfs(to,p);
    if(po != -1)return;
  }
  hist.pop();
  used[p] = false;
}

int main(){
  scanf("%d",&n);
  REP(i,n){
    int u,v;
    scanf("%d%d",&u,&v);
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0,-1);
  assert(po != -1);
  namo[po] = true;
  while(hist.top() != po){
    namo[hist.top()] = true;
    hist.pop();
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    if(namo[a] && namo[b]){
      puts("2");
    }else{
      puts("1");
    }
  }
  return 0;
}