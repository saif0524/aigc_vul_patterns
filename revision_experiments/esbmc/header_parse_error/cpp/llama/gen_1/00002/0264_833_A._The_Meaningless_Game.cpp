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

bool is_possible(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }

    while (b != 0) {
        if (a % b == 0) {
            return false;
        }

        long long temp = b;
        b = a % b;
        a = temp;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        bool possible = false;

        for (int i = 1; i <= 1000000; i++) {
            long long x = 1, y = 1;

            for (int j = 0; j < 40; j++) {
                if (((i << j) & a) != 0) {
                    x *= (i * i);
                }

                if (((i << j) & b) != 0) {
                    y *= i;
                }

                if (x > a || y > b) {
                    break;
                }
            }

            if (x == a && y == b) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}