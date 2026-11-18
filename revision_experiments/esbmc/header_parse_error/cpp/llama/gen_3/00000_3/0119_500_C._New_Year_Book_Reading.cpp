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

int dp[505][1005];
int w[505];
int b[1005];
int cnt[505];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        cnt[b[i]]++;
    }
    sort(w + 1, w + n + 1, [&](int a, int b){return cnt[a] > cnt[b];});
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += lower_bound(w + 1, w + n + 1, b[i]) - w - 1;
        int j = lower_bound(w + 1, w + n + 1, b[i]) - w - 1;
        swap(w[j], w[j + 1]);
    }
    printf("%d\n", sum);
    return 0;
}