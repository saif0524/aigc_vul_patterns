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

vector<int> represent(int n) {
    vector<int> res;
    int mx = 0;

    string str = to_string(n);
    for (char c : str) {
        mx = max(mx, c - '0');
    }

    string cur = str;
    while (cur != "0") {
        string next = "";
        for (char c : cur) {
            if (c == '0') {
                next += '0';
            } else {
                next += '1';
            }
        }
        res.push_back(stoi(next));
        cur = to_string(stoi(cur) - stoi(next));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> res = represent(n);
    cout << res.size() << endl;
    for (int v : res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}