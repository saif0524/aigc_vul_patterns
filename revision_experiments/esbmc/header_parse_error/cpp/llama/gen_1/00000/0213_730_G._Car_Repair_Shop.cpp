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
typedef pair<ll, ll> pii;

const int N = 5000005;
bool busy[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        ll s, d;
        cin >> s >> d;

        bool ok = true;
        for (int i = s; i < s + d; i++) {
            if (busy[i]) {
                ok = false;
                break;
            }
        }

        ll start = -1;
        if (ok) {
            start = s;
        } else {
            ll x = 1;
            while (true) {
                bool found = true;
                for (int i = x; i < x + d; i++) {
                    if (busy[i]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    start = x;
                    break;
                }
                x++;
            }
        }

        for (int i = start; i < start + d; i++) {
            busy[i] = true;
        }

        cout << start << " " << start + d - 1 << "\n";
    }

    return 0;
}