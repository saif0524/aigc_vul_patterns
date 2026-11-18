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

bool isEquivalent(string& a, string& b, int l1, int r1, int l2, int r2) {
    if (r1 - l1 + 1 == 1) return a[l1] == b[l2];
    int mid1 = (l1 + r1) / 2;
    int mid2 = (l2 + r2) / 2;
    return (isEquivalent(a, b, l1, mid1, l2, mid2) && isEquivalent(a, b, mid1 + 1, r1, mid2 + 1, r2)) ||
           (isEquivalent(a, b, l1, mid1, mid2 + 1, r2) && isEquivalent(a, b, mid1 + 1, r1, l2, mid2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(isEquivalent(a, b, 0, a.size() - 1, 0, b.size() - 1)) cout << "YES";
    else cout << "NO";
}