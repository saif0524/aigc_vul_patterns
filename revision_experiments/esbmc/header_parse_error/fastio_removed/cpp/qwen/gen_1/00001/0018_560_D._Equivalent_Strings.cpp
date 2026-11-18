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

bool equivalent(const string &a, const string &b) {
    if (a == b) return true;
    int n = a.size();
    if (n % 2 != 0) return false;
    string a1 = a.substr(0, n / 2);
    string a2 = a.substr(n / 2);
    string b1 = b.substr(0, n / 2);
    string b2 = b.substr(n / 2);
    return (equivalent(a1, b1) && equivalent(a2, b2)) || (equivalent(a1, b2) && equivalent(a2, b1));
}

int main(){
    ((void)0);
    ((void)0);
    string a, b;
    cin >> a >> b;
    if(equivalent(a, b)) cout << "YES";
    else cout << "NO";
}