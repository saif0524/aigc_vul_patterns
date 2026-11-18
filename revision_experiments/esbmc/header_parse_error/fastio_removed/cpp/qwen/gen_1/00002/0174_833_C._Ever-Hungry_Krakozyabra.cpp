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

set<string> uniqueTails;

string processNumber(long long num) {
    string s = to_string(num);
    sort(s.begin(), s.end(), greater<char>());
    size_t idx = s.find_first_not_of('0');
    return (idx == string::npos) ? "" : s.substr(idx);
}

int main(){
    ((void)0);
    ((void)0);
    long long L, R;
    cin >> L >> R;
    for(long long i = L; i <= R; ++i){
        uniqueTails.insert(processNumber(i));
    }
    cout << uniqueTails.size();
    return 0;
}