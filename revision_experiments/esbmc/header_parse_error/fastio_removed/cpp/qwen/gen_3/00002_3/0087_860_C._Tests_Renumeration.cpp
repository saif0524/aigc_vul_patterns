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

int main() {
    ((void)0);
    ((void)0);
    
    int n;
    cin >> n;
    vector<pair<string, int>> files(n);
    for (int i = 0; i < n; ++i) {
        cin >> files[i].first >> files[i].second;
    }
    
    int e = 0;
    for (auto& [name, type] : files) {
        if (type == 1) e++;
    }
    
    vector<string> newNames(n);
    int next_example = 1, next_regular = e + 1;
    for (auto& [name, type] : files) {
        if (type == 1) newNames[next_example++] = name;
        else newNames[next_regular++] = name;
    }
    
    vector<string> moves;
    for (int i = 1; i <= n; ++i) {
        string target = to_string(i);
        if (newNames[i] != target) {
            moves.push_back("move " + newNames[i] + " " + target);
            newNames[i] = target;
        }
    }
    
    cout << moves.size() << "\n";
    for (const auto& move : moves) {
        cout << move << "\n";
    }
    
    return 0;
}