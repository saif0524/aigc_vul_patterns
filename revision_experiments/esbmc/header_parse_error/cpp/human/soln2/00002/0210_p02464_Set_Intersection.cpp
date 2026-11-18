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

#define loop(x) for(int knzk=0;knzk<x;++knzk)
int in(){int x;scanf("%d",&x);return x;}

template<class T>
ostream& operator<<(ostream& os,set<T> const& v){for(auto itr=v.begin();itr!=v.end();++itr){if(itr!=v.begin())os<<' ';os<<*itr;}return os;}


signed main(){

  int n,m;
  set<int> s,t;
  cin>>n;
  loop(n)s.insert(in());
  cin>>m;
  loop(m)t.insert(in());

  set<int> result;
  set_intersection(
    s.begin(),s.end(),
    t.begin(),t.end(),
    inserter(result,result.end())
  );

  for(auto x:result)cout<<x<<endl;


}