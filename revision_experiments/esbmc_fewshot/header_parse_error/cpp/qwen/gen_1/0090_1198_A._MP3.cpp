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
    int n;
    long long I;
    cin >> n >> I;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int k = a.size();
    if(k == 1){
        cout << 0;
        return 0;
    }
    int max_bits = ceil(log2(k));
    if(max_bits * n <= I * 8){
        cout << 0;
        return 0;
    }
    int ans = n;
    for(int i = 0; i < k; i++){
        int left = i;
        int right = k - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int distinct = mid - i + 1;
            int bits = ceil(log2(distinct));
            long long total_bits = 1LL * bits * (n - (mid - i + 1));
            if(total_bits <= I * 8){
                ans = min(ans, mid - i + 1);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    cout << n - ans;
}