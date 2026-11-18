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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    long long ans_y = LLONG_MAX, ans_z = -1;
    for(int i=0;i<n;i++){
        if(i && a[i] == a[i-1]) continue;
        long long z = a[0] - a[i];
        if(z == 0) continue;
        long long y = 0;
        for(int j=0;j<n;j++){
            y += (a[j]/z) + (a[j]%z != 0);
        }
        if(y < ans_y){
            ans_y = y;
            ans_z = z;
        }
    }
    cout << ans_y << " " << ans_z << "\n";
}