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
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;

    set<string> seen;
    queue<string> q;
    q.push(s);
    seen.insert(s);

    while (!q.empty()) {
        string top = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                string diff = top;
                diff[i] = diff[i-1];
                if (seen.find(diff) == seen.end()) {
                    seen.insert(diff);
                    q.push(diff);
                }
            }
            if (i < n - 1) {
                string diff = top;
                diff[i] = diff[i+1];
                if (seen.find(diff) == seen.end()) {
                    seen.insert(diff);
                    q.push(diff);
                }
            }
        }
    }

    cout << seen.size() << endl;
    return 0;
}