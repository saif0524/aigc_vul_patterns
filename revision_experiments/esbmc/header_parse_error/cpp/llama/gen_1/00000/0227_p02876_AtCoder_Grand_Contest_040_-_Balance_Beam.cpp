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
typedef long long ll;

const int MAXN = 100005;

ll A[MAXN], B[MAXN];
int N;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool cmp(int a, int b) {
    return A[a] * B[b] > A[b] * B[a];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &A[i], &B[i]);
    }
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), cmp);
    ll a = 1, b = 1;
    for (int i = 0; i < N; i++) {
        ll na = a * B[p[i]];
        ll nb = b * A[p[i]];
        ll g = gcd(na, nb);
        a = na / g;
        b = nb / g;
    }
    printf("%lld %lld\n", a - 1, b);
    return 0;
}