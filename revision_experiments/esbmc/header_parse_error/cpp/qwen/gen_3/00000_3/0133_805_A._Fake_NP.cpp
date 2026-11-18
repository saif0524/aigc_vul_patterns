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
    long long l, r;
    cin >> l >> r;
    unordered_map<long long, int> freq;
    for(long long num = l; num <= r; num++){
        for(long long d = 2; d * d <= num; d++){
            if(num % d == 0){
                freq[d]++;
                if(d != num / d){
                    freq[num / d]++;
                }
            }
        }
    }
    long long max_freq_num = 0, max_freq = 0;
    for(const auto& [num, f] : freq){
        if(f > max_freq){
            max_freq = f;
            max_freq_num = num;
        }
    }
    cout << max_freq_num;
}