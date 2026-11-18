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
    
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for(auto &a : A) { cin >> a; }
    
    vector<long long> prefix(N+1, 0);
    for(long long i=0; i<N; i++){
        prefix[i+1] = (prefix[i] + A[i]) % M;
    }
    
    map<long long, long long> count;
    long long ans = 0;
    for(long long i=0; i<=N; i++){
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans;
}