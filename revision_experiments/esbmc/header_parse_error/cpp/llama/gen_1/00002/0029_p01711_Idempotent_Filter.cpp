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

const int MAX_N = 128;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    while (true) {
        cin >> input;
        if (input == "#") {
            break;
        }

        bool idempotent = true;
        for (int i = 0; i < MAX_N; ++i) {
            int output = input[i] - '0';
            int newOutput = 0;
            for (int mask = 0; mask < MAX_N; ++mask) {
                int center = (mask >> 3) & 1;
                int neighbors = mask & 7;
                int filterOutput = input[mask] - '0';
                if (center == output && neighbors == i) {
                    newOutput = filterOutput;
                    break;
                }
            }
            if (newOutput != output) {
                idempotent = false;
                break;
            }
        }
        cout << (idempotent ? "yes" : "no") << "\n";
    }

    return 0;
}