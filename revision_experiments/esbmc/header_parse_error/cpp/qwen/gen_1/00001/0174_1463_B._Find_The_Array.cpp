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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        long long S = accumulate(a.begin(), a.end(), 0LL);
        vector<long long> b(n, 1);
        for(int i=1; i<n; ++i){
            if(a[i] >= a[i-1] && a[i] % a[i-1] == 0){
                b[i] = a[i];
            }
            else if(a[i-1] >= a[i] && a[i-1] % a[i] == 0){
                b[i] = a[i];
            }
            else{
                b[i] = a[i-1];
            }
        }
        long long diff = 0;
        for(int i=0; i<n; ++i){
            diff += 2 * abs(a[i] - b[i]);
        }
        if(diff > S){
            bool fixed = false;
            for(int i=1; i<n && !fixed; ++i){
                if(b[i] != a[i]){
                    b[i] = a[i];
                    diff = 0;
                    for(int j=0; j<n; ++j){
                        diff += 2 * abs(a[j] - b[j]);
                    }
                    if(diff <= S){
                        fixed = true;
                    }
                    else{
                        b[i] = a[i-1];
                    }
                }
            }
        }
        for(auto x: b) cout << x << ' ';
        cout << '\n';
    }
}