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

struct BIT {
    int sz;
    vector<ll> data;

    BIT(int n) : sz(n), data(n + 1) {}

    void add(int idx, ll val) {
        for (++idx; idx <= sz; idx += idx & -idx)
            data[idx] += val;
    }

    ll query(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += data[idx];
        return res;
    }
};

int main(){
    int n;
    scanf("%d", &n);
    int len = (1 << n);
    vector<int> a(len);
    for(int &x : a) { scanf("%d", &x); }
    int m;
    scanf("%d", &m);
    vector<int> q(m);
    for(int &x : q) { scanf("%d", &x); }
    reverse(q.begin(), q.end());
    vector<int> pos(len);
    for(int i = 0; i < len; ++i){
        pos[a[i]] = i;
    }
    BIT bit(len + 1);
    for(int i = 0; i < len; ++i){
        bit.add(pos[i], 1);
    }
    ll inversions = 0;
    for(int i = 1; i < len; ++i){
        inversions += i - bit.query(pos[i]);
    }
    vector<ll> ans(m);
    for(int i = 0; i < m; ++i){
        ans[i] = inversions;
        int split = (1 << (n - q[i]));
        vector<int> new_a(len);
        for(int j = 0; j < split; ++j){
            reverse(a.begin() + j * split, a.begin() + (j + 1) * split);
        }
        for(int j = 0; j < len; ++j){
            bit.add(pos[a[j]], -1);
            inversions -= len - 1 - pos[a[j]] - bit.query(pos[a[j]]);
            pos[a[j]] = j;
            inversions += pos[a[j]] - bit.query(pos[a[j]]);
            bit.add(pos[a[j]], 1);
        }
    }
    for(int i = m - 1; i >= 0; --i){
        printf("%lld\n", ans[i]);
    }
}