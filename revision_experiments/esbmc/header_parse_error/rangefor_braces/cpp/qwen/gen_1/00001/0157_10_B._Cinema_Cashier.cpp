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
    int N, K;
    cin >> N >> K;
    vector<int> M(N);
    for (auto &m : M) { cin >> m; }

    vector<int> rowOccupied(K, 0);

    for (auto &m : M) {
        int bestX = -1, bestYl = -1, bestYr = -1;
        long long bestScore = LLONG_MAX;

        for (int x = 0; x < K; ++x) {
            if (K - rowOccupied[x] < m) continue;
            for (int yl = 0; yl <= K - m; ++yl) {
                bool canPlace = true;
                for (int y = yl; y < yl + m; ++y) {
                    if ((rowOccupied[x] >> y) & 1) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    int yr = yl + m - 1;
                    int center = K / 2;
                    long long score = 0;
                    for (int y = yl; y <= yr; ++y) {
                        score += abs(center - y);
                    }
                    if (score < bestScore || (score == bestScore && (x < bestX || (x == bestX && yl < bestYl)))) {
                        bestScore = score;
                        bestX = x;
                        bestYl = yl;
                        bestYr = yr;
                    }
                }
            }
        }

        if (bestX == -1) {
            cout << "-1\n";
        } else {
            cout << bestX + 1 << " " << bestYl + 1 << " " << bestYr + 1 << "\n";
            for (int y = bestYl; y <= bestYr; ++y) {
                rowOccupied[bestX] |= (1 << y);
            }
        }
    }

    return 0;
}