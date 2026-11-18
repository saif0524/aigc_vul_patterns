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

const int MOD = 998244353;

int n, c;
int a[3005];
int s[3005];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int p = 0; p <= n; p++) {
        s[p] = 0;
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                b.push_back(a[i]);
            }
        }

        int d = 0;
        for (int i = 1; i <= c; i++) {
            bool found = false;
            for (int j = 0; j < (int)b.size(); j++) {
                if (b[j] == i) {
                    found = true;
                    break;
                }
            }
            if (found) {
                d++;
            }
        }

        s[d] = (s[d] + 1) % MOD;
    }

    for (int i = 0; i <= n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}