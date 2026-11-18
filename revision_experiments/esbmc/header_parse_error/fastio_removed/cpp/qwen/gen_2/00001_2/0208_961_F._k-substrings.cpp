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

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    for(int k = 1; k <= (n+1)/2; ++k){
        string new_s = s.substr(k-1) + "#" + s.substr(0, n-k+1);
        vector<int> z = z_function(new_s);
        int max_odd = -1;
        for(int i = k+1; i < new_s.size(); ++i){
            if(i + z[i] == new_s.size() && z[i] % 2 == 1 && z[i] > max_odd){
                max_odd = z[i];
            }
        }
        ans[k-1] = max_odd;
    }
    for(int i = 0; i < n/2; ++i){
        cout << ans[i] << " ";
    }
    cout << ans[n/2] << "\n";
}