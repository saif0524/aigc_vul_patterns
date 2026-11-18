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

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int balance = 0;
    vector<pair<int,int>> ops;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            balance++;
        } else {
            if(balance > 0){
                ops.push_back({i-balance+1, i});
                balance--;
            }
        }
    }
    cout << ops.size() << "\n";
    for(auto& op : ops){
        cout << 2 << "\n";
        cout << op.first+1 << " " << op.second+1 << "\n";
    }
}