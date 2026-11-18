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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        long long S = 0;
        for(auto &x: a) cin >> x, S += x;
        vector<long long> b(n,1);
        long long current_diff = 0;
        for(int i=0;i<n;i++){
            long long original_diff = abs(a[i] - b[i]);
            if(2 * (current_diff + original_diff) > S){
                b[i] = a[i];
                current_diff += original_diff;
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(a[i] % b[j] == 0 || b[j] % a[i] == 0){
                        b[j] = a[i];
                        current_diff += abs(a[j] - b[j]);
                        if(2 * current_diff > S) break;
                    }
                }
            }
        }
        for(auto &x: b) cout << x << " ";
        cout << "\n";
    }
}