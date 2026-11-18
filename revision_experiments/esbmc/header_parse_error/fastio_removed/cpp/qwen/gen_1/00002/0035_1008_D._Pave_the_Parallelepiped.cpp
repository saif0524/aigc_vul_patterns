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
    int t;
    cin >> t;
    while(t--){
        long long A, B, C;
        cin >> A >> B >> C;
        if(A > B) swap(A, B);
        if(B > C) swap(B, C);
        if(A > B) swap(A, B);
        long long ans = 0;
        for(long long a = 1; a*a*a <= A*B*C; a++){
            if(A*B*C % a != 0) continue;
            long long bc = A*B*C / a;
            for(long long b = a; b*b <= bc; b++){
                if(bc % b != 0) continue;
                long long c = bc / b;
                if(b <= c) ans++;
            }
        }
        cout << ans << "\n";
    }
}