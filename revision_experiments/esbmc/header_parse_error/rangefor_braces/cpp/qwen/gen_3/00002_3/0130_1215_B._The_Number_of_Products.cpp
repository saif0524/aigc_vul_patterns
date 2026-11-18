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
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) { cin >> x; }
    long long pos = 0, neg = 0, zero = 0, last_zero = -1;
    int current_sign = 1;
    long long current_pos = 0, current_neg = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < 0) current_sign *= -1;
        if(a[i] == 0){
            last_zero = i;
            zero += i + 1;
            current_sign = 1;
            current_pos = 0;
            current_neg = 0;
        }
        else{
            if(current_sign == 1){
                current_pos += i - last_zero;
                pos += current_pos;
            }
            else{
                current_neg += i - last_zero;
                neg += current_neg;
            }
        }
    }
    long long total_subarrays = (long long)n * (n + 1) / 2;
    long long non_zero_subarrays = total_subarrays - zero;
    cout << neg << " " << non_zero_subarrays - neg << "\n";
}