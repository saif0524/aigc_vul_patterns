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

string to_string(long long n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s += char('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ((void)0);
    ((void)0);
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for(auto &x : a) cin >> x;
    vector<long long> b(M);
    for(auto &x : b) cin >> x;
    long long Q;
    cin >> Q;
    vector<long long> d(Q);
    for(auto &x : d) cin >> x;
    vector<vector<string>> grid(N, vector<string>(M));
    vector<long long> prefix_sum(N * M + 1, 0);
    for(long long i = 0; i < N; ++i){
        for(long long j = 0; j < M; ++j){
            grid[i][j] = to_string(a[i] * b[j]);
            prefix_sum[i * M + j + 1] = prefix_sum[i * M + j] + grid[i][j].size();
        }
    }
    string ans;
    for(auto &x : d){
        if(x > prefix_sum.back()){
            ans += 'x';
            continue;
        }
        long long row = lower_bound(prefix_sum.begin(), prefix_sum.end(), x) - prefix_sum.begin();
        long long col = row % M;
        row /= M;
        long long offset = x - prefix_sum[row * M + col];
        ans += grid[row][col][offset - 1];
    }
    cout << ans;
}