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

bool isLucky(int x) {
    while (x > 0) {
        int digit = x % 10;
        if (digit!= 4 && digit!= 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool check(int n, long long k) {
    if (k > factorial(n)) {
        return false;
    }
    return true;
}

long long calculate(int n, long long k) {
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        numbers.push_back(i + 1);
    }
    k--;
    for (int i = 0; i < n; i++) {
        int f = factorial(n - i - 1);
        int index = k / f;
        k %= f;
        a[i] = numbers[index];
        numbers.erase(numbers.begin() + index);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isLucky(i + 1) && isLucky(a[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    if (!check(n, k)) {
        cout << -1 << endl;
    } else {
        cout << calculate(n, k) << endl;
    }
    return 0;
}