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

const int MAXN = 200005;

int n, q;
long long a[MAXN];
long long lazy[MAXN];

void push_down(int idx, int l, int r) {
    if (lazy[idx] > 0) {
        a[l] = max(a[l], lazy[idx]);
        if (l < r) {
            lazy[2*idx] = max(lazy[2*idx], lazy[idx]);
            lazy[2*idx+1] = max(lazy[2*idx+1], lazy[idx]);
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int l, int r, int ql, int qr, long long val) {
    push_down(idx, l, r);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        lazy[idx] = val;
        push_down(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2*idx, l, mid, ql, qr, val);
    update(2*idx+1, mid+1, r, ql, qr, val);
}

long long query(int idx, int l, int r, int pos) {
    push_down(idx, l, r);
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    if (pos <= mid) return query(2*idx, l, mid, pos);
    else return query(2*idx+1, mid+1, r, pos);
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < q; i++){
        int t, x;
        long long y;
        cin >> t >> x >> y;
        if(t == 1){
            update(1, 1, n, 1, x, y);
        }
        else{
            long long money = y;
            int meals = 0;
            for(int j = x; j <= n; j++){
                long long cost = query(1, 1, n, j);
                if(money >= cost){
                    money -= cost;
                    meals++;
                }
                else break;
            }
            cout << meals << "\n";
        }
    }
}