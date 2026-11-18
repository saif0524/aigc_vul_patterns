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

string s;
int n, k;
set<string> st;

int solve() {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < s.length() - 1; j++) {
            string temp = s.substr(j, 2);
            sort(temp.begin(), temp.end());
            if (st.find(temp) != st.end()) {
                ans++;
                s.erase(j, 1);
                i = 0;
                j = -1;
            }
        }
    }
    return ans;
}

int main() {
    cin >> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string temp;
        cin >> temp;
        sort(temp.begin(), temp.end());
        st.insert(temp);
    }
    cout << solve();
}