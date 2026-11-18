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
double mem[51][5001];
int x,y,z,v[100],used[51][5001];
struct po{int e,a;};
po E[101];

double dfs(int pos,int mo){
  if(pos==y) return mo;
  if(used[pos][mo]) return mem[pos][mo];
  used[pos][mo]=1;
  
  for(int i=0;i<x;i++) {
    int npos=min(y,pos+v[i]),nmo=mo;
    int e=E[npos].e, a=E[npos].a;
    if(e){
      if(e==1)npos=min(y,npos+a);
      if(e==2)nmo+=a;
      if(e==3)nmo=max(0,nmo-a);
    }
    mem[pos][mo] += dfs(npos,nmo)/x;
  }
  return mem[pos][mo];
}

int main(){
  while(1){
  cin>>x>>y>>z;
  if(!x&&!y&&!z)break;
  for(int i=0;i<x;i++)cin>>v[i];
  memset(E,0,sizeof(E));
  for(int i=0,a;i<z;i++)cin>>a,cin>>E[a].e>>E[a].a;

  memset(used,0,sizeof(used));  
  for(int i=0;i<51;i++)for(int j=0;j<5001;j++) mem[i][j]=0;
  cout <<(int)dfs(0,0)<<endl;
  }
  return 0;
}