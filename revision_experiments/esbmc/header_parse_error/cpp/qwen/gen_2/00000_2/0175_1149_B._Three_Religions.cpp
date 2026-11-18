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

bool is_possible(const string &s, const string &a, const string &b, const string &c) {
    vector<int> p(3, 0);
    for (char ch : s) {
        int i = -1;
        if (p[0] < a.size() && a[p[0]] == ch) i = 0;
        else if (p[1] < b.size() && b[p[1]] == ch) i = 1;
        else if (p[2] < c.size() && c[p[2]] == ch) i = 2;
        if (i != -1) ++p[i];
    }
    return p[0] == a.size() && p[1] == b.size() && p[2] == c.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string a, b, c;
    while(q--){
        char op;
        cin >> op;
        int idx;
        cin >> idx;
        if(op == '+'){
            char c;
            cin >> c;
            if(idx == 1) a.push_back(c);
            else if(idx == 2) b.push_back(c);
            else c.push_back(c);
        }
        else{
            if(idx == 1) a.pop_back();
            else if(idx == 2) b.pop_back();
            else c.pop_back();
        }
        if(is_possible(s, a, b, c)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}