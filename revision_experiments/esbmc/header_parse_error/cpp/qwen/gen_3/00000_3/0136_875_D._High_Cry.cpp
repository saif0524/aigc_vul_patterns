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
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    vector<int> max_or(n);
    max_or[0] = a[0];
    for(int i=1;i<n;i++) max_or[i] = max_or[i-1] | a[i];
    int ans = 0;
    for(int r=1;r<n;r++) {
        int l = 0, r2 = r;
        while(l < r2) {
            int mid = (l+r2)/2;
            if(max_or[mid] > *max_element(a.begin() + mid + 1, a.begin() + r + 1)) r2 = mid;
            else l = mid + 1;
        }
        ans += r - l;
    }
    cout << ans;
}