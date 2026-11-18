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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int N, K;
        cin >> N >> K;
        if (N == 0 && K == 0) break;
        if (K == 1) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    cout << '.';
                }
                cout << '\n';
            }
            cout << '\n';
            continue;
        }
        vector<string> layout(N, string(N, '.'));
        long long tot = 1;
        for (int i = 0; i < N && tot < K; ++i) {
            for (int j = 0; j < N && tot < K; ++j) {
                if (i % 2 == 0 && j % 2 == 0) {
                    layout[i][j] = 'E';
                    tot *= 2;
                } else if (i % 2 == 1 && j % 2 == 1) {
                    layout[i][j] = 'E';
                    tot *= 2;
                }
            }
        }
        if (K > tot) {
            cout << "No\n\n";
        } else {
            K -= 1;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        if (K & 1) layout[i][j] = 'E';
                        K >>= 1;
                    } else if (i % 2 == 1 && j % 2 == 1) {
                        if (K & 1) layout[i][j] = 'E';
                        K >>= 1;
                    }
                }
            }
            for (const auto& row : layout) {
                cout << row << '\n';
            }
            cout << '\n';
        }
    }
}