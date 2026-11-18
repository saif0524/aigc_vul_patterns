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

bool canSum(int a, int b) {
    while (a || b) {
        if ((a % 10 == 0) || (b % 10 == 0)) {
            a /= 10;
            b /= 10;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<int> d(k);
    for (int &x : d) { cin >> x; }
    
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        bool valid = true;
        for (int x : result) {
            if (!canSum(d[i], x)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            result.push_back(d[i]);
        }
    }
    
    cout << result.size() << endl;
    for (int x : result) { cout << x << " "; }
    cout << endl;
}