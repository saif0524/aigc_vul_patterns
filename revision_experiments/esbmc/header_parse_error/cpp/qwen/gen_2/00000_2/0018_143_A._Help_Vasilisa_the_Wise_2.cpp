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

bool solve(int r1, int r2, int c1, int c2, int d1, int d2, vector<int>& used, int a, int b, int c, int d) {
    if (used[a]) return false;
    used[a] = 1;
    if (used[b]) return false;
    used[b] = 1;
    if (used[c]) return false;
    used[c] = 1;
    if (used[d]) return false;
    used[d] = 1;
    
    if (a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 && a + d == d1 && b + c == d2) {
        return true;
    }
    
    used[a] = 0;
    used[b] = 0;
    used[c] = 0;
    used[d] = 0;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    
    vector<int> used(10, 0);
    bool found = false;
    int a, b, c, d;
    
    for(a = 1; a <= 9; ++a){
        for(b = 1; b <= 9; ++b){
            for(c = 1; c <= 9; ++c){
                for(d = 1; d <= 9; ++d){
                    if(solve(r1, r2, c1, c2, d1, d2, used, a, b, c, d)){
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        if(found) break;
    }
    
    if(found){
        cout << a << " " << b << "\n" << c << " " << d;
    }
    else{
        cout << "-1";
    }
}