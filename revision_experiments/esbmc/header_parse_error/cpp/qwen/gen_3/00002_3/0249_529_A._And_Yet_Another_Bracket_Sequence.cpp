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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> bal(n + 1);
    for (int i = 0; i < n; ++i) {
        bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
    }

    int min_bal = *min_element(bal.begin(), bal.end());
    string best;
    for (int shift = 0; shift < n; ++shift) {
        int open = 0, close = 0;
        string cur;
        for (int i = 0; i < n; ++i) {
            int idx = (shift + i) % n;
            if (s[idx] == '(') {
                if (bal[shift + i + 1] - bal[shift] + open - close >= 0) {
                    cur += '(';
                    open++;
                }
            } else {
                if (open - close > 0) {
                    cur += ')';
                    close++;
                } else {
                    open++;
                    cur += '(';
                }
            }
        }
        while (close < open) {
            cur += ')';
            close++;
        }
        if (best.empty() || cur < best) {
            best = cur;
        }
    }
    cout << best << endl;
}