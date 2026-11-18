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

const int N = 1e6 + 10;

int n, x[N], y[N];
int b[N];
string ans;

bool check() {
    int suna = 0, sung = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            suna += x[i];
        } else {
            sung += y[i];
        }
    }
    if (abs(suna - sung) > 500) return false;
    return true;
}

int main() {
    ((void)0); ((void)0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        b[i] = (x[i] > y[i]);
    }

    do {
        if (check()) {
            for (int i = 0; i < n; ++i) {
                ans += (b[i] ? 'A' : 'G');
            }
            cout << ans << endl;
            return 0;
        }
    } while (next_permutation(b, b + n));

    cout << -1 << endl;

    return 0;
}