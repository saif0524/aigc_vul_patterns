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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= a[i];
        }

        if (ans == 0) {
            cout << "DRAW\n";
        } else {
            for (int i = 30; i >= 0; --i) {
                if ((ans >> i) & 1) {
                    int cnt = 0;
                    for (int j = 0; j < n; ++j) {
                        if (((a[j] >> i) & 1) == 1) {
                            ++cnt;
                        }
                    }
                    if (cnt % 4 == 1 || cnt % 4 == 2) {
                        cout << "WIN\n";
                    } else {
                        cout << "LOSE\n";
                    }
                    break;
                }
            }
        }
    }

    return 0;
}