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

bool isLucky(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int findPermutation(int n, int k) {
    if (k > factorial(n)) {
        return -1;
    }

    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    k--;
    string permutation = "";
    for (int i = n - 1; i >= 0; i--) {
        int fact = factorial(i);
        int index = k / fact;
        k %= fact;
        permutation += to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);
        if (i > 0) {
            permutation += " ";
        }
    }

    stringstream ss(permutation);
    string token;
    int count = 0;
    int pos = 1;
    while (ss >> token) {
        int num = stoi(token);
        if (isLucky(pos) && isLucky(num)) {
            count++;
        }
        pos++;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << findPermutation(n, k) << endl;
    return 0;
}