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
    while (cin >> n && n != 0) {
        vector<string> actions(n);
        for (auto &action : actions) { cin >> action; }
        
        int count = 0;
        bool leftUp = false, rightUp = false;
        for (const auto &action : actions) {
            if (action == "lu") {
                if (!leftUp && !rightUp) leftUp = true;
            } else if (action == "ru") {
                if (!leftUp && !rightUp) rightUp = true;
            } else if (action == "ld") {
                if (leftUp) {
                    leftUp = false;
                    if (!rightUp) count++;
                }
            } else if (action == "rd") {
                if (rightUp) {
                    rightUp = false;
                    if (!leftUp) count++;
                }
            }
        }
        cout << count << "\n";
    }
}