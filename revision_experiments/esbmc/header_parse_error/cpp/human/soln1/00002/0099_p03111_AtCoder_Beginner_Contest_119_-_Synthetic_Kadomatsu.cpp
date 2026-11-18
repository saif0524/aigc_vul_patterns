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

int INF=10000000;
int N,A,B,C;
vector<int> L;

int rec(int i, int a, int b, int c){
    if(i==N){
        if(!a||!b||!c) return INF;
        return abs(a-A)+abs(b-B)+abs(c-C);
    }
    
    int res=rec(i+1,a,b,c);
    res=min(res, rec(i+1, a + L[i], b, c) + (a ? 10 : 0));
    res=min(res, rec(i+1, a, b + L[i], c) + (b ? 10 : 0));
    res=min(res, rec(i+1, a, b, c + L[i]) + (c ? 10 : 0));
    
    return res;
}



int main(void){
    cin>>N>>A>>B>>C;
    L.resize(N);
    for(int i=0;i<N;i++) cin>>L[i];
    
    cout<<rec(0,0,0,0)<<endl;
    
}