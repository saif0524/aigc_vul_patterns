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

double compute_weakness(const vector<int>& a, double x) {
    double max_segment = 0, min_segment = 0, current = 0;
    for (int num : a) {
        current += num - x;
        max_segment = max(max_segment, current);
        min_segment = min(min_segment, current);
    }
    return max_segment - min_segment;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    double left = *min_element(a.begin(), a.end());
    double right = *max_element(a.begin(), a.end());
    double best = 1e18;
    for(int iter = 0; iter < 100; iter++){
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        double val1 = compute_weakness(a, mid1);
        double val2 = compute_weakness(a, mid2);
        if(val1 < val2) right = mid2;
        else left = mid1;
    }
    best = min(best, min(compute_weakness(a, left), compute_weakness(a, right)));
    cout << setprecision(18) << best << endl;
}