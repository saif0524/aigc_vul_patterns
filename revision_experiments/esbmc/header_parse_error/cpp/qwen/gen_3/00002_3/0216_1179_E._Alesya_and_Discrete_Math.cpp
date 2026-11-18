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

long long query(int func, long long pos) {
    cout << "? " << func << " " << pos << endl;
    fflush(stdout);
    long long res;
    cin >> res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, L;
    cin >> n >> L;
    long long step = L/n;
    vector<pair<long long, long long>> segments(n);
    for(int i = 0; i < n; i++){
        long long left = 0, right = 1e18;
        while(right - left > 1){
            long long mid = (left + right)/2;
            if(query(i+1, mid) >= step){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        segments[i] = {left, right};
    }
    cout << "!" << endl;
    for(auto &p : segments){
        cout << p.first << " " << p.second << endl;
    }
}