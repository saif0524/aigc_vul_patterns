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
#define ll long long
using namespace std;
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,k;
    cin>>n>>k;
    ll a[n][2];
    for(ll i=0;i<n;i++)
      cin>>a[i][0]>>a[i][1];
      ll ans=-1;
      bool flag=0;
    for(ll i=0;i<n;i++)
    {
      flag=0;
      for(ll j=0;j<n;j++)
      {
        if((abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))>k)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        ans=1;
        break;
      }
    }
    cout<<ans<<"\n";
  }
}