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

string s, t;
int cnt[26];

bool makeGreater(int pos) {
    if (pos == s.size()) return false;
    int idx = s[pos] - 'a';
    for (int i = idx + 1; i < 26; i++) {
        if (cnt[i] > 0) {
            char temp = s[pos];
            s[pos] = i + 'a';
            cnt[idx]--;
            cnt[i]--;
            if (s.compare(t) > 0) return true;
            cnt[idx]++;
            cnt[i]++;
            s[pos] = temp;
        }
    }
    return false;
}

string nextGreater(string s, string t) {
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int pos = 0;
    while (pos < s.size() && pos < t.size()) {
        if (s[pos] < t[pos]) {
            return "-1";
        }
        if (s[pos] > t[pos]) {
            break;
        }
        pos++;
    }
    if (pos == t.size()) {
        if (pos == s.size()) {
            return "-1";
        }
    }
    if (makeGreater(pos)) {
        int i = pos + 1;
        while (i < s.size()) {
            int idx = -1;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] > 0) {
                    if (idx == -1) idx = j;
                    else idx = idx < j ? idx : j;
                }
            }
            s[i] = idx + 'a';
            cnt[idx]--;
            i++;
        }
        return s;
    }
    return "-1";
}

int main() {
    cin >> s >> t;
    cout << nextGreater(s, t) << endl;
    return 0;
}