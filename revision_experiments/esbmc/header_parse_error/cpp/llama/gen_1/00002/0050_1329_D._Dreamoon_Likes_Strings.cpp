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

const int maxn = 200010;

int T, n;
char a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        n = strlen(a);
        vector<pair<int, int>> ans;
        int left = 0, right = n - 1;
        while (left < right) {
            if (a[left] == a[left + 1]) {
                ans.push_back({left + 1, left + 2});
                left++;
            } else if (a[right] == a[right - 1]) {
                ans.push_back({right, right + 1});
                right--;
            } else {
                ans.push_back({left + 1, right + 1});
                left++;
                right--;
            }
        }
        if (left == right) {
            ans.push_back({left + 1, left + 1});
        }
        printf("%d\n", (int)ans.size());
        for (auto p : ans) {
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}