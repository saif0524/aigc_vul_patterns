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

typedef long long ll;

int main(){
    ((void)0);
    ((void)0);
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    for(auto &a: A) cin >> a;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> min_heap;
    for(int i=0;i<N;i++){
        min_heap.push({A[i], i});
    }
    
    ll total_cost = 0;
    while(min_heap.size() > 1){
        auto first = min_heap.top(); min_heap.pop();
        auto second = min_heap.top(); min_heap.pop();
        total_cost += (second.second - first.second) * D + first.first + second.first;
        min_heap.push({first.first + second.first, first.second});
    }
    
    cout << total_cost;
    return 0;
}