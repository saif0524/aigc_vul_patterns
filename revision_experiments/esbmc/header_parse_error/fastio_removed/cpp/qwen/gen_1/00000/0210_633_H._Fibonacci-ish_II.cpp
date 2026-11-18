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

const int MAXN = 30005;
const int MAXQ = 30005;
const int MAXLOG = 16;

int n, m, q;
int a[MAXN];
int fenwick[MAXN];
int block_size;
int block_index[MAXN];
pair<int, int> queries[MAXQ];
int ans[MAXQ];

inline int get(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum = (sum + fenwick[idx]) % m;
    }
    return sum;
}

inline void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        fenwick[idx] = (fenwick[idx] + val) % m;
    }
}

int fib[MAXN];

inline void preprocess_fib() {
    fib[1] = fib[2] = 1;
    for (int i = 3; i < MAXN; ++i) {
        fib[i] = (fib[i-1] + fib[i-2]) % m;
    }
}

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        return block_index[l] == block_index[other.l] ? r < other.r : l < other.l;
    }
};

vector<Query> queries_list;

inline void mo() {
    sort(begin(queries_list), end(queries_list));
    
    int cur_l = 1, cur_r = 0;
    int cur_ans = 0;
    
    unordered_map<int, int> frequency;
    
    auto add_element = [&](int idx) {
        if (frequency[a[idx]] == 0) {
            cur_ans = (cur_ans + (long long)a[idx] * fib[frequency.size() + 1]) % m;
        }
        frequency[a[idx]]++;
    };
    
    auto remove_element = [&](int idx) {
        frequency[a[idx]]--;
        if (frequency[a[idx]] == 0) {
            cur_ans = (cur_ans - (long long)a[idx] * fib[frequency.size()]) % m;
            if (cur_ans < 0) cur_ans += m;
        }
    };
    
    for (const auto& query : queries_list) {
        while (cur_l > query.l) {
            cur_l--;
            add_element(cur_l);
        }
        while (cur_r < query.r) {
            cur_r++;
            add_element(cur_r);
        }
        while (cur_l < query.l) {
            remove_element(cur_l);
            cur_l++;
        }
        while (cur_r > query.r) {
            remove_element(cur_r);
            cur_r--;
        }
        ans[query.idx] = cur_ans;
    }
}

int order[MAXQ];

int main(){
    ((void)0);
    ((void)0);
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    
    cin >> q;
    
    block_size = sqrt(n);
    
    for(int i=1;i<=n;i++){
        block_index[i] = (i-1) / block_size + 1;
    }
    
    for(int i=0;i<q;i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    
    preprocess_fib();
    
    for(int i=0;i<q;i++){
        queries_list.push_back({queries[i].l, queries[i].r, i});
    }
    
    mo();
    
    for(int i=0;i<q;i++){
        order[queries[i].idx] = i;
    }
    
    for(int i=0;i<q;i++){
        cout << ans[order[i]] << "\n";
    }
}