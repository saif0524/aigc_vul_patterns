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

const int MAX_N = 30000;

long long fib[MAX_N + 1];

void calculateFibonacci(int n, int m) {
    fib[1] = 1 % m;
    fib[2] = 1 % m;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }
}

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    calculateFibonacci(n, m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        set<int> uniqueElements;
        for (int j = l; j <= r; j++) {
            uniqueElements.insert(a[j]);
        }

        vector<int> sortedUniqueElements(uniqueElements.begin(), uniqueElements.end());
        sort(sortedUniqueElements.begin(), sortedUniqueElements.end());

        long long potential = 0;
        for (int j = 0; j < sortedUniqueElements.size(); j++) {
            potential = (potential + (long long)sortedUniqueElements[j] * fib[j + 1]) % m;
        }

        cout << potential << '\n';
    }

    return 0;
}