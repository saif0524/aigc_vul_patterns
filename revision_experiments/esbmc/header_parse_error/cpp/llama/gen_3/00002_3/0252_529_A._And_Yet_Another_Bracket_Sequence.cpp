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
    int n = s.size();
    vector<string> candidates;

    for (int i = 0; i < n; i++) {
        string t = s.substr(i) + s.substr(0, i);
        int balance = 0, min_balance = 0;
        int max_balance = 0, end_balance = 0;
        for (char c : t) {
            if (c == '(') {
                balance++;
                max_balance = max(max_balance, balance);
            } else {
                balance--;
                min_balance = min(min_balance, balance);
                end_balance = balance;
            }
        }
        int opening = -min_balance;
        int closing = max_balance - end_balance;
        string prefix(opening, '(');
        string suffix(closing, ')');
        string candidate = prefix + t + suffix;
        candidates.push_back(candidate);
    }

    sort(candidates.begin(), candidates.end());
    cout << candidates[0] << endl;
    return 0;
}