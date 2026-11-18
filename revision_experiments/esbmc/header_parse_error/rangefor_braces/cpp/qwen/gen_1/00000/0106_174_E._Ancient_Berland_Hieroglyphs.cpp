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
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    vector<int> an(a.begin(), a.end());
    vector<int> bn(b.begin(), b.end());
    for(int i = 0; i < la-1; ++i){
        an.push_back(a[i]);
    }
    for(int i = 0; i < lb-1; ++i){
        bn.push_back(b[i]);
    }
    int res = 0;
    for(int i = 0; i < la; ++i){
        vector<int> ind(lb+1, -1);
        for(int j = 0; j < lb; ++j){
            ind[bn[j]] = j;
        }
        int mx = 0;
        for(int j = 0; j < la; ++j){
            if(ind[an[j+i]] != -1){
                mx = max(mx, ind[an[j+i]]+1);
            }
            else{
                break;
            }
        }
        res = max(res, mx);
    }
    cout << res;
}