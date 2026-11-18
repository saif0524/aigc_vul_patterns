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
    int n, w;
    long long k;
    cin >> n >> w >> k;
    vector<int> a(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    
    long long ans = 0;
    for(int start = 0; start < n; start++) {
        long long time = 0, pleasure = 0;
        int partial = 0;
        for(int i = start; i < n && time < k; i++) {
            if(time + t[i] <= k) {
                pleasure += a[i];
                time += t[i];
            } else {
                if(partial < w && time + t[i] / 2 <= k) {
                    pleasure += a[i];
                    time += t[i] / 2;
                    partial++;
                } else break;
            }
        }
        ans = max(ans, pleasure);
    }
    cout << ans << "\n";
}