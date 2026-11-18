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

string names[50001];
int lengths[50001];
int dp[50001][50001];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
        lengths[i] = names[i].length();
    }

    int max_length = 0;

    for (int i = 0; i < n; i++) {
        bool found_matching = false;

        for (int j = i; j >= 0; j--) {
            if (names[j][lengths[j] - 1] == names[i][0]) {
                found_matching = true;
                dp[i][i] = max(dp[i][i], lengths[i]);
                if (j != i) {
                    dp[i][j] = lengths[i] + lengths[j];
                    max_length = max(max_length, dp[i][j]);
                    for (int k = j - 1; k >= 0; k--) {
                        if (dp[k][j] > 0 && names[k][lengths[k] - 1] == names[i][0]) {
                            dp[i][k] = max(dp[i][k], dp[k][j] + lengths[i]);
                            max_length = max(max_length, dp[i][k]);
                        }
                    }
                }
            }
        }

        if (!found_matching && i == 0) {
            max_length = lengths[i];
        }
    }

    cout << max_length << endl;

    return 0;
}