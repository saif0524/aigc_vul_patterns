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
int sqrtN;
int fenwick[MAXN];
int fib[MAXN];
int bit[MAXLOG][MAXN];
int moc[MAXQ];
int idx[MAXQ];
pair<int, int> queries[MAXQ];

void add(int &x, int y) {
    x += y;
    if (x >= m) x -= m;
}

void add_fenwick(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        add(fenwick[idx], val);
    }
}

void add_bit(int idx, int val) {
    for (int i = 0; i < MAXLOG; i++) {
        add(bit[i][idx], (val >> i) & 1);
    }
}

int query_fenwick(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        add(res, fenwick[idx]);
    }
    return res;
}

int query_bit(int idx) {
    int res = 0;
    for (int i = 0; i < MAXLOG; i++) {
        res |= ((query_fenwick(bit[i][idx]) & 1) << i);
    }
    return res;
}

void clear_fenwick() {
    memset(fenwick, 0, sizeof(fenwick));
}

void clear_bit() {
    memset(bit, 0, sizeof(bit));
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
        moc[i] = i;
    }
    sqrtN = sqrt(n);
    sort(moc, moc+q, [&](int i, int j){
        return make_pair(queries[i].first/sqrtN, queries[i].second) < make_pair(queries[j].first/sqrtN, queries[j].second);
    });
    fib[1] = fib[2] = 1;
    for(int i=3;i<=n;i++) fib[i] = (fib[i-1] + fib[i-2]) % m;
    int l = 0, r = -1;
    for(int i=0;i<q;i++){
        int L = queries[moc[i]].first;
        int R = queries[moc[i]].second;
        while(r < R) {
            r++;
            int val = a[r];
            add_fenwick(val, 1);
            add_bit(val, 1);
        }
        while(l > L) {
            l--;
            int val = a[l];
            add_fenwick(val, 1);
            add_bit(val, 1);
        }
        while(r > R) {
            int val = a[r];
            add_fenwick(val, -1);
            add_bit(val, -1);
            r--;
        }
        while(l < L) {
            int val = a[l];
            add_fenwick(val, -1);
            add_bit(val, -1);
            l++;
        }
        vector<int> unique_elements;
        for(int j=0;j<=10000;j++){
            if(query_fenwick(j) > 0){
                unique_elements.push_back(j);
            }
        }
        int ans = 0;
        int sz = unique_elements.size();
        for(int j=0;j<sz;j++){
            int val = unique_elements[j];
            int rank = query_bit(val);
            add(ans, ((long long)fib[rank] * val) % m);
        }
        idx[moc[i]] = ans;
    }
    for(int i=0;i<q;i++){
        cout << idx[i] << "\n";
    }
}