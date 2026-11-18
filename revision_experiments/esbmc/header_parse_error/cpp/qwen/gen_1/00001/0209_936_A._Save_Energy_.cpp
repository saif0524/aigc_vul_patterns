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
    long long k, d, t;
    cin >> k >> d >> t;
    double total_time = 0;
    double on_time = 0;
    double off_time = 0;
    while(t > 0){
        if(t <= k){
            total_time += t;
            on_time += t;
            t = 0;
        }
        else{
            total_time += k;
            on_time += k;
            t -= k;
            if(t > 0){
                if(t <= d){
                    total_time += t * 2.0;
                    off_time += t;
                    t = 0;
                }
                else{
                    total_time += d * 2.0;
                    off_time += d;
                    t -= d;
                }
            }
        }
        if(t > 0){
            if(total_time + d <= total_time + k){
                total_time += d;
            }
            else{
                total_time += k;
                on_time += k;
                t -= k;
            }
        }
    }
    printf("%.10f\n", total_time);
}