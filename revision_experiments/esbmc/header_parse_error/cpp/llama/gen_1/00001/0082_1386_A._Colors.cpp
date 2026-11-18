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

void solve() {
    long long N;
    cin >> N;
    long long low = 1;
    long long high = N;
    vector<bool> used(N + 1);
    long long color = 1;
    used[color] = true;
    cout << "? " << color << endl;
    cin.ignore();
    while (low < high) {
        long long mid = (high + low) / 2;
        long long next = color + mid;
        if (next >= 1 && next <= N && !used[next]) {
            cout << "? " << next << endl;
            used[next] = true;
            int ans;
            cin >> ans;
            cin.ignore();
            if (ans == 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
            color = next;
        } else {
            next = color - mid;
            if (next >= 1 && next <= N && !used[next]) {
                cout << "? " << next << endl;
                used[next] = true;
                int ans;
                cin >> ans;
                cin.ignore();
                if (ans == 0) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
                color = next;
            } else {
                for (int i = 1; i <= N; i++) {
                    if (!used[i]) {
                        next = i;
                        break;
                    }
                }
                cout << "? " << next << endl;
                used[next] = true;
                color = next;
                cin.ignore();
            }
        }
    }
    cout << "= " << low << endl;
}

int! main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}