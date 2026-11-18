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

unordered_map<int, int> memo;

int countSteps(int n) {
    if (n < 10) return 0;
    if (memo.count(n)) return memo[n];
    int steps = -1;
    string s = to_string(n);
    for (int i = 1; i < s.size(); ++i) {
        int left = stoi(s.substr(0, i));
        int right = stoi(s.substr(i));
        if (left == 0 || right == 0) continue;
        int next = left * right;
        int subSteps = countSteps(next);
        if (subSteps != -1) {
            if (steps == -1) steps = 1 + subSteps;
            else steps = min(steps, 1 + subSteps);
        }
    }
    return memo[n] = steps;
}

int main(){
    ((void)0);
    ((void)0);
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        cout << countSteps(n) << "\n";
    }
}