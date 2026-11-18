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
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    string ans = "";

    for (char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cnt++;
                tmp += c;
            }
        }
        if (cnt >= 100) {
            for (int i = 0; i < 50; i++) {
                tmp += c;
            }
            ans = tmp;
            break;
        }
    }

    if (ans.size()) {
        cout << ans << '\n';
        return 0;
    }

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = i; j < n; j++) {
            tmp += s[j];
            mp[tmp]++;
        }
    }

    ans = "";
    for (auto& p : mp) {
        string key = p.first;
        string rev = key;
        reverse(rev.begin(), rev.end());
        if (key == rev && key.size() > ans.size()) {
            ans = key;
        }
    }

    cout << ans << '\n';
    return 0;
}