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
#define ll long long int

int main(){
    ((void)0);
    ((void)0);
    ((void)0);
  ll t;
  cin>>t;
  while(t--)
  {
      ll n;
      cin>>n;
    ll a[n+1],even_sum=0,sum=0;
    a[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==0)
            even_sum+=a[i];
            sum+=a[i];
    }
    if(2*(even_sum)<=sum)
    {
        for(ll i=1;i<=n;i++)
        {
            if(i%2==0)
                cout<<1<<" ";
            else
                cout<<a[i]<<" ";
        }
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            if(i%2==1)
                cout<<1<<" ";
            else
                cout<<a[i]<<" ";
        }
    }
      cout<<"\n";
  }


  return 0;
}