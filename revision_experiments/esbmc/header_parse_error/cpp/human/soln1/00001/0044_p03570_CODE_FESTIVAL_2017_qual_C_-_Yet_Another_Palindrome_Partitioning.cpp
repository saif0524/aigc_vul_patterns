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
char ax[200005];
int dp[200005];
int len;
map<int,int> m;

int main()
{
    scanf("%s",ax);
    int i,j,a,b,now=0;
    len = strlen(ax);
    m[0]=len;
    for(i=len-1;i>=0;i--){
        now ^= (1<<(ax[i]-'a'));
        dp[i]=len-i;
        if(m.count(now))dp[i]=min(dp[i],dp[m[now]]+1);
        for(j=0;j<26;j++){
            a = now^(1<<j);
            if(!m.count(a))continue;
            dp[i]=min(dp[i],dp[m[a]]+1);
        }
       if(!m.count(now))m[now]=i;
       else if(dp[i]<dp[m[now]])m[now]=i;
    }
    printf("%d",dp[0]);
    return 0;
}