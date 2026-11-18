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
        vector<string> moves(n);
        for (int i = 0; i < n; ++i) cin >> moves[i];
        
        int count = 0;
        bool on_floor = true;
        bool left_up = false, right_up = false;
        
        for (const string& move : moves) {
            if (on_floor) {
                if (move == "lu" || move == "ru") {
                    if (move == "lu") left_up = true;
                    else right_up = true;
                    if (left_up && right_up) {
                        count++;
                        on_floor = false;
                        left_up = false;
                        right_up = false;
                    }
                }
            } else {
                if (move == "ld" || move == "rd") {
                    if (move == "ld") left_up = false;
                    else right_up = false;
                    if (!left_up && !right_up) {
                        on_floor = true;
                    }
                }
            }
        }
        cout << count << "\n";
    }
}