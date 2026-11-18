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
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a < b;
    });
    set<char> s;
    for (const auto& str : strs) {
        for (char c : str) {
            s.insert(c);
        }
    }
    vector<char> chars(s.begin(), s.end());
    sort(chars.begin(), chars.end());
    map<char, char> mp;
    vector<int> used(26, 0);
    string res;
    bool ok = true;
    for (const auto& str : strs) {
        int i = 0, j = str.size() - 1;
        bool flag = false;
        while (i < str.size()) {
            if (!mp.count(str[i])) {
                if (used[str[i] - 'a'] == 1) {
                    ok = false;
                    break;
                }
                used[str[i] - 'a'] = 1;
                if (j > i) {
                    if (mp.count(str[j])) {
                        if (mp[str[j]] != str[i]) {
                            ok = false;
                            break;
                        }
                    } else {
                        mp[str[j]] = str[i];
                    }
                    j--;
                } else flag = true;
            } else {
                if (mp[str[i]] != str[j]) {
                    ok = false;
                    break;
                }
                j--;
            }
            i++;
        }
        if (!flag) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
    } else {
        for (char c : chars) {
            if (!mp.count(c)) {
                res += c;
            } else {
                res += c;
                res += mp[c];
            }
        }
        cout << res << endl;
    }
    return 0;
}