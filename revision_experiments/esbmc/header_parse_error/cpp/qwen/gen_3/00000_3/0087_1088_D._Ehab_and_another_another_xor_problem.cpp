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

int main(){
    long long a=0, b=0;
    for(int i=29;i>=0;--i){
        long long c=(1LL<<i), d=0;
        cout<<"? "<<c<<" "<<d<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        if(x==-2) return 0;
        if(x==1) a|=c;
        c=0, d=(1LL<<i);
        cout<<"? "<<c<<" "<<d<<endl;
        fflush(stdout);
        cin>>x;
        if(x==-2) return 0;
        if(x==-1) b|=c;
    }
    cout<<"! "<<a<<" "<<b<<endl;
    fflush(stdout);
    return 0;
}