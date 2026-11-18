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
    long long a, b, mod;
    cin >> a >> b >> mod;
    string s1, s2;
    for(long long i = 0; i <= a; ++i){
        s1 = to_string(i);
        while(s1.size() < 9) s1 = '0' + s1;
        for(long long j = 0; j <= b; ++j){
            s2 = to_string(j);
            while(s2.size() < 9) s2 = '0' + s2;
            string combined = s1 + s2;
            long long num = stoll(combined);
            if(num % mod == 0){
                cout << "2";
                return 0;
            }
        }
    }
    cout << "1 " << s1;
}