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

vector<ll> calc_zigzag(const vector<int>& a, int z) {
    int n = a.size();
    vector<ll> zigzag(n, 0);
    for (int i = 0; i < n; ++i) {
        int idx = i % z;
        if (idx < (z + 1) / 2) {
            zigzag[i] = (ll)a[i] * (idx + 1);
        } else {
            zigzag[i] = (ll)a[i] * (z - idx);
        }
    }
    for (int i = 1; i < n; ++i) {
        zigzag[i] += zigzag[i - 1];
    }
    return zigzag;
}

int main() {
    ((void)0);
    ((void)0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<ll>> precomputed_zigzag(7);
    for (int i = 2; i <= 6; ++i) {
        precomputed_zigzag[i] = calc_zigzag(a, i);
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            --p;
            a[p] = v;
            for (int i = 2; i <= 6; ++i) {
                int idx = p % i;
                if (idx < (i + 1) / 2) {
                    precomputed_zigzag[i][p] = (ll)v * (idx + 1);
                } else {
                    precomputed_zigzag[i][p] = (ll)v * (i - idx);
                }
                for (int j = p + 1; j < n; ++j) {
                    precomputed_zigzag[i][j] = precomputed_zigzag[i][j - 1] + precomputed_zigzag[i][j];
                }
                if (p > 0) {
                    for (int j = p; j < n; ++j) {
                        precomputed_zigzag[i][j] -= precomputed_zigzag[i][p - 1];
                    }
                }
            }
        } else {
            int l, r, z;
            cin >> l >> r >> z;
            --l;
            --r;
            if (l == 0) {
                cout << precomputed_zigzag[z][r] << "\n";
            } else {
                cout << precomputed_zigzag[z][r] - precomputed_zigzag[z][l - 1] << "\n";
            }
        }
    }
    
    return 0;
}