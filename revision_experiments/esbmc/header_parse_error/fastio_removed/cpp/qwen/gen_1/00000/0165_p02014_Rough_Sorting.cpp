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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<N;i++) if(A[i-1] > A[i]) pq.emplace(A[i-1], i-1);
    while(K > 0 && !pq.empty()){
        auto [val, idx] = pq.top();
        pq.pop();
        if(idx >= N-1 || A[idx+1] != val) continue;
        swap(A[idx], A[idx+1]);
        K--;
        if(idx > 0 && A[idx-1] > A[idx]) pq.emplace(A[idx-1], idx-1);
        if(A[idx] > A[idx+1]) pq.emplace(A[idx], idx);
    }
    for(auto &x: A) cout << x << "\n";
}