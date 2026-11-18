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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(auto &x : A) cin >> x;
    priority_queue<array<int, 2>> pq;
    for(int i=0; i<N; ++i){
        int v = abs(A[i] - i);
        if(A[i] > i) pq.push({A[i] - i, -1}); // can move right
        else if(A[i] < i) pq.push({i - A[i], 1}); // can move left
        else v = 0;
    }
    long long ans = 0;
    while(M && !pq.empty()){
        auto [v, dir] = pq.top(); pq.pop();
        if(dir == -1){ // move right
            ans += v;
            M--;
            int j = A[lower_bound(A.begin(), A.end(), A[lower_bound(A.begin(), A.end(), v + 1) - 1] + 1) - 1] - 1;
            if(A[j] - j - 1 > 0){
                pq.push({A[j] - j - 1, -1});
            }
        }
        else{ // move left
            ans += v;
            M--;
            int j = *lower_bound(A.begin(), A.end(), A[lower_bound(A.begin(), A.end(), v - 1) - 1] - 1);
            if(j - (A[lower_bound(A.begin(), A.end(), j - 1)] - 1) > 0){
                pq.push({j - (A[lower_bound(A.begin(), A.end(), j - 1)] - 1), 1});
            }
        }
    }
    for(int i=0; i<N; ++i) ans += abs(A[i] - i);
    cout << ans << "\n";
}