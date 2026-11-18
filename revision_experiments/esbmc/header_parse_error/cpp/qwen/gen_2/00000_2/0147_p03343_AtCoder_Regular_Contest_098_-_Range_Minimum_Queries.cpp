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
    for(auto &a : A) cin >> a;
    
    vector<int> removed;
    for(int i = 0; i < Q; i++){
        int min_val = INT_MAX, min_idx = -1;
        for(int j = 0; j <= N-K; j++){
            int current_min = *min_element(A.begin() + j, A.begin() + j + K);
            if(current_min < min_val){
                min_val = current_min;
                min_idx = j;
            }
        }
        removed.push_back(A[min_idx + distance(A.begin() + min_idx, min_element(A.begin() + min_idx, A.begin() + min_idx + K))]);
        A.erase(A.begin() + min_idx + distance(A.begin() + min_idx, min_element(A.begin() + min_idx, A.begin() + min_idx + K)));
        N--;
    }
    
    int X = *max_element(removed.begin(), removed.end());
    int Y = *min_element(removed.begin(), removed.end());
    cout << X - Y;
}