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
const int maxn=1e5+10;
int d[maxn],n,m,l,r;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        for(int a=1,b;a<=l-1;a=b+1){
            b=(l-1)/((l-1)/a);
            int y=(l-1)/a;
            int L=a,R=min(r/(y+1),b);
            //cout<<L<<" "<<R<<endl;
            d[L]+=1,d[R+1]-=1;
        }
        d[l]+=1,d[r+1]-=1;
    }
    for(int i=1;i<=m;i++){
        d[i]=d[i-1]+d[i];
        printf("%d\n",d[i]);
    }

}