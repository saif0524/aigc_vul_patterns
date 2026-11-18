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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(auto &x: A) { cin >> x; }
    long long ans = 0;
    multiset<int> small, large;
    for(int i=0; i<N; i++){
        if(A[i] <= i){
            small.insert(A[i]);
        }
        else{
            large.insert(A[i]);
        }
    }
    while(M > 0 && !small.empty() && !large.empty()){
        auto it_s = small.begin();
        auto it_l = --large.end();
        if(*it_l - *it_s > 1){
            int s = *it_s;
            int l = *it_l;
            small.erase(it_s);
            large.erase(it_l);
            small.insert(s+1);
            large.insert(l-1);
            M--;
        }
        else{
            break;
        }
    }
    for(int i=0; i<N; i++){
        if(small.count(A[i])){
            ans += abs(A[i] - i);
            small.erase(small.find(A[i]));
        }
        else{
            ans += abs(A[i] - i);
        }
    }
    cout << ans << "\n";
}