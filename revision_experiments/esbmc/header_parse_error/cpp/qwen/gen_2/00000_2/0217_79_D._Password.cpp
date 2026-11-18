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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> x(k);
    for(auto &xi : x) cin >> xi;
    vector<int> a(l);
    for(auto &ai : a) cin >> ai;
    
    vector<int> target(n+1, 0);
    for(auto xi : x) target[xi] = 1;
    
    int result = 0;
    for(int i=1; i<=n; ++i){
        if(target[i] == 0) continue;
        bool found = false;
        for(auto ai : a){
            if(i + ai - 1 > n) continue;
            found = true;
            result++;
            for(int j=i; j<=i+ai-1; ++j) target[j] = 1 - target[j];
            break;
        }
        if(!found) {
            cout << -1;
            return 0;
        }
    }
    
    cout << result;
}