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
    ((void)0);
    ((void)0);
    int n;
    long long sx, sy;
    cin >> n >> sx >> sy;
    vector<long long> xl, yl;
    for(int i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        if(x>sx){
            xl.push_back(x-sx);
        }
        if(x<sx){
            xl.push_back(sx-x);
        }
        if(y>sy){
            yl.push_back(y-sy);
        }
        if(y<sy){
            yl.push_back(sy-y);
        }
    }
    sort(xl.begin(),xl.end());
    sort(yl.begin(),yl.end());
    long long px,py;
    if(xl.empty()){
        px = sx;
    }else{
        px = sx + xl[xl.size()/2] * (xl.size()&1?1:-1);
    }
    if(yl.empty()){
        py = sy;
    }else{
        py = sy + yl[yl.size()/2] * (yl.size()&1?1:-1);
    }
    cout << (int)xl.size()-(int)count(xl.begin(), xl.end(), 0) +
            (int)yl.size()-(int)count(yl.begin(), yl.end(), 0) -
            (int)count_if(xl.begin(), xl.end(), [](long long x){return x==0;}) *
            (int)count_if(yl.begin(), yl.end(), [](long long x){return x==0;})
            - (int)count_if(xl.begin(), xl.end(), [](long long x){return x>0;}) *
               (int)count_if(yl.begin(), yl.end(), [](long long x){return x>0;})
            - (int)count_if(xl.begin(), xl.end(), [](long long x){return x<0;}) *
               (int)count_if(yl.begin(), yl.end(), [](long long x){return x<0;}) << "\n";
    cout << px << " " << py;
}