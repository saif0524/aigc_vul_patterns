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

const int MAX_Y = 55;

double dp[MAX_Y];

int main() {
    ((void)0);
    ((void)0);

    while (true) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        if (X == 0 && Y == 0 && Z == 0) break;

        vector<int> V(X);
        for (int i = 0; i < X; i++) cin >> V[i];

        vector<tuple<int, int, int>> events(Z);
        for (int i = 0; i < Z; i++) {
            int N, E, A;
            cin >> N >> E >> A;
            events[i] = {N, E, A};
        }

        sort(events.begin(), events.end());

        fill(dp, dp + Y + 1, 0.0);

        dp[0] = 0.0;

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int next = min(i + V[j], Y);

                bool eventFound = false;
                for (const auto& event : events) {
                    int N, E, A;
                    tie(N, E, A) = event;
                    if (N == next) {
                        if (E == 1) next += A;
                        else if (E == 2) dp[next] += A;
                        else if (E == 3) dp[next] -= A;

                        if (dp[next] < 0) dp[next] = 0;
                        eventFound = true;
                        break;
                    }
                }

                if (!eventFound) {
                    dp[next] += dp[i];
                }
            }

            for (int j = 0; j < X; j++) {
                dp[i] = 0.0;
            }
        }

        double answer = 0.0;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int next = min(i + V[j], Y);
                answer += dp[next] / (double)X;
            }
        }

        cout << (int)answer << '\n';
    }

    return 0;
}