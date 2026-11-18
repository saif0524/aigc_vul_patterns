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

vector<int> tetrahedral;
vector<int> odd_tetrahedral;

void generate_tetrahedral_numbers() {
    for (int n = 1; ; ++n) {
        int t_n = n * (n + 1) * (n + 2) / 6;
        if (t_n >= 1000000) break;
        tetrahedral.push_back(t_n);
        if (t_n % 2 == 1) {
            odd_tetrahedral.push_back(t_n);
        }
    }
}

int min_tetrahedral_sum(int num, const vector<int>& nums) {
    vector<int> dp(num + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= num; ++i) {
        for (int x : nums) {
            if (x > i) break;
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    return dp[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    generate_tetrahedral_numbers();
    int n;
    while (cin >> n && n != 0) {
        int min_tetra = min_tetrahedral_sum(n, tetrahedral);
        int min_odd_tetra = min_tetrahedral_sum(n, odd_tetrahedral);
        cout << min_tetra << " " << min_odd_tetra << "\n";
    }
    return 0;
}