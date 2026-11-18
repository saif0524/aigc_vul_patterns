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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; i++) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    sort(constraints.begin(), constraints.end());

    int low = pow(10, n - 1);
    int high = pow(10, n);

    for (int num = low; num < high; num++) {
        string str = to_string(num);
        bool valid = true;
        for (int i = 0; i < m; i++) {
            if (str[constraints[i].first - 1] - '0' != constraints[i].second) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << num << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}