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

set<string> titles;

bool is_original(const string& title) {
    for (const auto& s : titles) {
        if (s.find(title) != string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string title;
    for (int i = 0; i < n; i++) {
        cin >> title;
        titles.insert(title);
    }
    string result;
    for (int len = 1; len <= 20; len++) {
        for (int first = 0; first < 26; first++) {
            string current(1, 'a' + first);
            if (len == 1 && is_original(current)) {
                result = current;
                goto end;
            }
            for (int second = 0; second < 26; second++) {
                current.push_back('a' + second);
                if (len == 2 && is_original(current)) {
                    result = current;
                    goto end;
                }
                for (int third = 0; third < 26; third++) {
                    current.push_back('a' + third);
                    if (len == 3 && is_original(current)) {
                        result = current;
                        goto end;
                    }
                    current.pop_back();
                }
                current.pop_back();
            }
            current.pop_back();
        }
    }
end:
    cout << result << "\n";
    return 0;
}