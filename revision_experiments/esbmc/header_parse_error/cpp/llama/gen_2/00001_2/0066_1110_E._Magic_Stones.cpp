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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] != b[i]) {
            bool found = false;
            for (int j = i; j >= 1; --j) {
                if (a[j - 1] != b[j - 1]) {
                    break;
                }
                a[j] = a[j - 1] + a[j + 1] - a[j];
                if (a[j] == b[j]) {
                    found = true;
                }
            }
            if (!found) {
                for (int j = i; j < n - 1; ++j) {
                    if (a[j + 1] != b[j + 1]) {
                        break;
                    }
                    a[j] = a[j - 1] + a[j + 1] - a[j];
                    if (a[j] == b[j]) {
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No\n";
                return 0;
            }
        }
    }
    bool equal = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            equal = false;
            break;
        }
    }
    if (equal) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}