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
    int T;
    cin >> T;
    while(T--){
        long long n, l, r;
        cin >> n >> l >> r;
        vector<long long> cycle;
        if(n == 2){
            if(l == 1) cycle = {1, 2, 1};
            else if(l == 2) cycle = {2, 1, 2};
        }
        else{
            for(long long i=1; i<n; i++) cycle.push_back(i);
            cycle.push_back(n);
            for(long long i=n-1; i>0; i--){
                cycle.push_back(i);
                if(i > 1) cycle.push_back(n);
            }
        }
        long long total = n * n - n + 1;
        l--, r--;
        long long start = l % (total - 1);
        vector<long long> result;
        for(long long i=0; i<r-l+1; i++){
            result.push_back(cycle[(start + i) % (total - 1)]);
        }
        for(auto &x: result) cout << x << " ";
        cout << "\n";
    }
}