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
typedef vector<pii> vpii;
typedef vector<vi> vvi;

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, s, e) for (int i = (s); i < (e); i++)
#define all(x) x.begin(), x.end()

int main() {
    int n, k;
    cin >> n >> k;
    vvi g(n);
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    vi A(n, 1);
    rep(i, n) {
        A[i] += 2 * g[i].size();
    }

    set<int> s;
    rep(i, n) {
        s.insert(A[i]);
    }

    vi B(n, 0);

    rep(i, n) {
        if (s.count(A[i])) {
            s.erase(A[i]);
            B[i] = 1;
            A[i]--;
        }
    }

    vi C(k, 0);
    rep(i, k) {
        int x, y;
        x = g[i % n][i / n];
        y = i % n;
        if (A[x] == A[y]) {
            if (B[x]) {
                C[i] = 2;
                A[x] -= 2;
                A[y]++;
            } else if (B[y]) {
                C[i] = 0;
                A[y] -= 2;
                A[x]++;
            }
        }
    }

    rep(i, k) {
        int x, y;
        x = g[i % n][i / n];
        y = i % n;
        if (A[x] == A[y]) {
            C[i] = 1;
            A[x]--;
            A[y]++;
        }
    }

    int ans = 0;
    rep(i, n) {
        ans += B[i];
    }
    cout << ans << endl;
    rep(i, n) {
        if (B[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    rep(i, k) {
        int x, y;
        x = g[i % n][i / n];
        y = i % n;
        cout << x + 1 << " " << y + 1 << " " << C[i] << endl;
    }

    return 0;
}