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

#define MOD 1000000007

struct FenwickTree {
    vector<long long> data;
    int n;

    FenwickTree(int _n) : n(_n + 1) {
        data.assign(n, 0);
    }

    void add(int idx, long long value) {
        for (++idx; idx < n; idx += idx & -idx) {
            data[idx] += value;
            if (data[idx] >= MOD) data[idx] -= MOD;
        }
    }

    long long sum(int idx) {
        long long ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += data[idx];
            if (ret >= MOD) ret -= MOD;
        }
        return ret;
    }

    long long range_sum(int left, int right) {
        return (sum(right) - sum(left - 1) + MOD) % MOD;
    }
};

int main(){
    ((void)0);
    ((void)0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n), w(n);
    for(auto &x: a) cin >> x;
    for(auto &x: w) cin >> x;
    FenwickTree POS(n), W(n);
    for(int i = 0; i < n; i++){
        POS.add(i, a[i]);
        W.add(i, w[i]);
    }
    while(q--){
        long long x, y;
        cin >> x >> y;
        if(x < 0){
            x = -x;
            long long old_w = w[x-1];
            w[x-1] = y;
            W.add(x-1, y - old_w);
        }
        else{
            long long l = x-1, r = y-1;
            long long med_idx = (l + r) / 2;
            long long med_sum = (med_idx - l + 1) * W.range_sum(l, med_idx) - POS.range_sum(l, med_idx) +
                              POS.range_sum(med_idx+1, r) - (r - med_idx) * W.range_sum(med_idx+1, r);
            long long ans = med_sum;
            if((r - l + 1) % 2 == 0){
                long long alt_sum = POS.range_sum(l, med_idx) - (med_idx - l + 1) * W.range_sum(l, med_idx) +
                                  (r - med_idx) * W.range_sum(med_idx+1, r) - POS.range_sum(med_idx+1, r);
                ans = min(ans, alt_sum);
            }
            cout << ans % MOD << "\n";
        }
    }
}