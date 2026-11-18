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
        long long d, k;
        cin >> d >> k;
        long long max_dist_squared = d * d;
        int moves = 0;
        long long x = 0, y = 0;
        while(true){
            bool can_move = false;
            if(x + k <= d && (x + k) * (x + k) + y * y <= max_dist_squared){
                x += k;
                can_move = true;
            }
            else if(y + k <= d && x * x + (y + k) * (y + k) <= max_dist_squared){
                y += k;
                can_move = true;
            }
            if(!can_move) break;
            moves++;
        }
        if(moves % 2 == 0) cout << "Utkarsh\n";
        else cout << "Ashish\n";
    }
}