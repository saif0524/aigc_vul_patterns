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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &x: P) cin >> x;
    vector<deque<int>> A(N+1);
    for(int i=0;i<N;i++){
        A[P[i]].push_back(i);
    }
    vector<int> ans(N);
    int last = -1;
    for(int i=1;i<=N;i++){
        if(A[i].empty()) continue;
        int idx = A[i].back();
        A[i].pop_back();
        while(!A[i].empty()){
            int nidx = A[i].back();
            if(idx - nidx >= K){
                idx = nidx;
                A[i].pop_back();
            }
            else break;
        }
        last = idx;
        ans[idx] = i;
    }
    int num = 1;
    for(int i=0;i<N;i++){
        if(ans[i] == 0){
            while(!A[num].empty()) num++;
            ans[i] = num++;
        }
    }
    for(auto &x: ans) cout << x << "\n";
}