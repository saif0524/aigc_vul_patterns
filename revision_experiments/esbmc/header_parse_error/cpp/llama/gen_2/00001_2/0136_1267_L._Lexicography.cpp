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

    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> words(n);
    int start = 0;
    int end = k - 1;
    int idx = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = start; j <= end; ++j) {
            words[j].push_back(s[idx]);
            idx++;
        }

        if (end < n - 1) {
            int diff = end - start + 1;
            start = end + 1;
            end = start + diff - 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        while (words[i].size() < l) {
            words[i].push_back(s[idx]);
            idx++;
        }
        cout << words[i] << "\n";
    }

    return 0;
}