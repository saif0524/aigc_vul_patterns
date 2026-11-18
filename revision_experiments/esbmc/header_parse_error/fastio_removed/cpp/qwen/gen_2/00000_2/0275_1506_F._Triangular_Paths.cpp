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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> r(n), c(n);
        for(auto &x: r) cin >> x;
        for(auto &x: c) cin >> x;
        long long cost = 0;
        for(int i = 1; i < n; i++){
            long long dr = r[i] - r[i-1];
            long long dc = c[i] - c[i-1];
            if(dr == dc){
                cost += 0;
            }
            else if(dr > dc){
                long long diff = dr - dc;
                if((r[i-1] + c[i-1]) % 2 == 0){
                    cost += diff / 2;
                }
                else{
                    cost += (diff + 1) / 2;
                }
            }
            else{
                long long diff = dc - dr;
                if((r[i-1] + c[i-1]) % 2 == 0){
                    cost += (diff + 1) / 2;
                }
                else{
                    cost += diff / 2;
                }
            }
        }
        cout << cost << "\n";
    }
}