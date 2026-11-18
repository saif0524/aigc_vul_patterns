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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    vector<int> sorted_a(a.begin()+l-1, a.begin()+r);
    vector<int> sorted_b(b.begin()+l-1, b.begin()+r);
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    if(sorted_a != sorted_b) {
        cout << "LIE";
    } else {
        vector<int> freq_a(n+1, 0), freq_b(n+1, 0);
        for(int i = 0; i < n; ++i){
            if(i < l-1 || i > r-1){
                freq_a[a[i]]++;
                freq_b[b[i]]++;
            }
        }
        if(freq_a == freq_b) {
            cout << "TRUTH";
        } else {
            cout << "LIE";
        }
    }
}