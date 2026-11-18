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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;

const int INF = 1e9;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vi> perm;
    perm.push_back(p);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i <= c) {
                vi ne = p;
                reverse(ne.begin() + i, ne.begin() + j + 1);
                bool ok = true;
                for (int k = 0; k < perm.size(); k++) {
                    if (ne == perm[k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    perm.push_back(ne);
                }
            }
        }
    }
    sort(perm.begin(), perm.end());
    while (q--) {
        ll pos, ind;
        cin >> pos >> ind;
        pos -= 1;
        ind -= 1;
        if (ind >= perm.size()) {
            cout << "-1\n";
            continue;
        }
        cout << perm[ind][pos] << "\n";
    }
}

int main() {
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}