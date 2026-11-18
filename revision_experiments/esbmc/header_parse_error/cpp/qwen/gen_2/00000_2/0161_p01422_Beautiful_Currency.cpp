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

double check(vector<int> a, double m) {
    for (int i = 1; i < a.size(); ++i) {
        if (ceil(a[i] / (1 + m)) < a[i-1]) return -1;
    }
    double max_ratio = 0;
    for (int i = 0; i < a.size(); ++i) {
        double new_val = ceil(a[i] / (1 + m));
        while (i > 0 && new_val < a[i-1]) new_val++;
        max_ratio = max(max_ratio, (a[i] - new_val) / (double)a[i]);
    }
    return max_ratio;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    double l = 0, r = 1;
    for(int t = 0; t < 100; t++){
        double m = (l + r) / 2;
        if(check(a, m) >= 0) r = m;
        else l = m;
    }
    printf("%.12f\n", check(a, r));
}