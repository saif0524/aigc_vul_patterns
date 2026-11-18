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
    string S;
    cin >> S;
    int n = S.size();
    vector<int> zeros, ones;
    for(int i=0; i<n; ++i){
        if(S[i] == '0') zeros.push_back(i);
        if(S[i] == '1') ones.push_back(i);
    }
    int q = n - zeros.size() - ones.size();
    int ans = n;
    for(int k=0; k<=q; ++k){
        int z = zeros.size() + k;
        int o = ones.size() + (q-k);
        int min_diff = abs(z - o);
        for(int i=0; i<n; ++i){
            if(S[i] == '0'){
                if(i < zeros.size()){
                    z--;
                } else {
                    o++;
                }
            } else if(S[i] == '1'){
                if(i < ones.size()){
                    o--;
                } else {
                    z++;
                }
            } else {
                if(zeros.size() + k > i){
                    z--;
                } else {
                    o++;
                }
            }
            min_diff = min(min_diff, abs(z - o));
        }
        ans = min(ans, min_diff);
    }
    cout << ans;
}