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

const int N = 200005;

int a_count[30], b_count[30], c_count[30];

void count_chars(const string& s, int* count) {
    for (char c : s) {
        count[c - 'a']++;
    }
}

int main() {
    ((void)0);
    ((void)0);

    string a, b, c;
    cin >> a >> b >> c;

    count_chars(a, a_count);
    count_chars(b, b_count);
    count_chars(c, c_count);

    int b_taken = 0, c_taken = 0;
    string result;

    for (int i = 0; i <= (int)a.size(); i++) {
        bool take_b = false, take_c = false;
        if (i < (int)a.size()) {
            int j;
            for (j = 0; j < (int)b.size(); j++) {
                if (b[j] != a[i + j]) break;
            }
            if (j == (int)b.size()) {
                bool possible = true;
                for (int k = 0; k < 26; k++) {
                    if (a_count[k] - b_count[k] * (b_taken + 1) < 0) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    take_b = true;
                }
            }
        }
        if (i < (int)a.size()) {
            int j;
            for (j = 0; j < (int)c.size(); j++) {
                if (c[j] != a[i + j]) break;
            }
            if (j == (int)c.size()) {
                bool possible = true;
                for (int k = 0; k < 26; k++) {
                    if (a_count[k] - c_count[k] * (c_taken + 1) < 0) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    take_c = true;
                }
            }
        }
        if (take_b && take_c) {
            bool b_possible = true, c_possible = true;
            for (int k = 0; k < 26; k++) {
                if (a_count[k] - b_count[k] * (b_taken + 1) - c_count[k] * c_taken < 0) {
                    c_possible = false;
                }
                if (a_count[k] - b_count[k] * b_taken - c_count[k] * (c_taken + 1) < 0) {
                    b_possible = false;
                }
            }
            if (b_possible) {
                result += b;
                for (int k = 0; k < 26; k++) {
                    a_count[k] -= b_count[k];
                }
                i += (int)b.size() - 1;
                b_taken++;
            } else {
                result += c;
                for (int k = 0; k < 26; k++) {
                    a_count[k] -= c_count[k];
                }
                i += (int)c.size() - 1;
                c_taken++;
            }
        } else if (take_b) {
            result += b;
            for (int k = 0; k < 26; k++) {
                a_count[k] -= b_count[k];
            }
            i += (int)b.size() - 1;
            b_taken++;
        } else if (take_c) {
            result += c;
            for (int k = 0; k < 26; k++) {
                a_count[k] -= c_count[k];
            }
            i += (int)c.size() - 1;
            c_taken++;
        } else {
            result += a[i];
            for (int k = 0; k < 26; k++) {
                a_count[k]--;
            }
        }
    }
    cout << result << endl;
    return 0;
}