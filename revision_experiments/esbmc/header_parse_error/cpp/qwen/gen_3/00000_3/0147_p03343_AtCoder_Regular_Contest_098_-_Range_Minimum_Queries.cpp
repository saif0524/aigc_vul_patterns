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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    
    map<int, int> min_count;
    multiset<int> window;
    
    for(int i = 0; i < K; i++){
        window.insert(A[i]);
    }
    min_count[*window.begin()]++;
    
    for(int i = K; i < N; i++){
        window.insert(A[i]);
        min_count[*window.begin()]++;
        window.erase(window.find(A[i - K]));
        if(window.count(*window.begin()) == 0) min_count.erase(*window.begin());
    }
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto &[val, cnt]: min_count) min_heap.push(val);
    
    int X = 0, Y = INT_MAX;
    for(int q = 0; q < Q; q++){
        int current_min = min_heap.top();
        min_heap.pop();
        Y = min(Y, current_min);
        if(min_count[current_min] > 1){
            min_count[current_min]--;
            min_heap.push(current_min);
        } else {
            min_count.erase(current_min);
            if(!min_heap.empty()) X = max(X, min_heap.top());
        }
    }
    
    cout << X - Y;
}