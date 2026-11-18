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
    long long a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    int res = 0;
    if((abs(x1 + y1) % (1LL << a) == 0 || abs(x1 - y1) % (1LL << b) == 0) && (abs(x2 + y2) % (1LL << a) == 0 || abs(x2 - y2) % (1LL << b) == 0))
        res = 1;
    if(abs(x1 - x2) % 2 == 0 && abs(y1 - y2) % 2 == 0){
        if(res == 1){
            if(abs(x1 - x2) % (1LL << a) == 0 || abs(y1 - y2) % (1LL << a) == 0 || abs(x1 + y1 - x2 - y2) % (1LL << b) == 0 || abs(x1 - y1 - x2 + y2) % (1LL << b) == 0)
                res = 2;
        }
    }
    else{
        if(res == 1)
            res = 2;
    }
    cout << res;
}