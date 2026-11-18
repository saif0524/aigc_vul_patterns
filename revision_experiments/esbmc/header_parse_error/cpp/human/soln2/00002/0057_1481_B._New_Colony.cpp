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

int main()
{
    ll t,i,j;
    cin>>t;
    while(t--)
    {
       ll n,k;
       cin>>n>>k;
       ll a[n];
       for(i=0;i<n;i++)
       cin>>a[i];
       bool ans=false;
       for(i=0;i<k;i++)
       {
           j=0;
           while(a[j]>=a[j+1]&&j<n-1)
           {
               j++;
           }
           if(j==n-1)
           {
               ans=true;
               break;
           }
           else 
           a[j]++;
       }
       if(ans)
       cout<<"-1"<<endl;
       else
       cout<<j+1<<endl;
    }
}