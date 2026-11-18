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

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    
    int gcd_all = A[0];
    for(int i = 1; i < N; ++i) {
        gcd_all = __gcd(gcd_all, A[i]);
    }
    
    if(gcd_all != 1) {
        cout << "not coprime";
        return 0;
    }
    
    bool pairwise_coprime = true;
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(__gcd(A[i], A[j]) != 1) {
                pairwise_coprime = false;
                break;
            }
        }
        if(!pairwise_coprime) break;
    }
    
    if(pairwise_coprime) {
        cout << "pairwise coprime";
    } else {
        cout << "setwise coprime";
    }
    
    return 0;
}