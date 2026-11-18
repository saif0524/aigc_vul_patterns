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
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> r(n), c(n);
        for(long long i=0;i<n;i++) cin >> r[i];
        for(long long i=0;i<n;i++) cin >> c[i];
        vector<long long> points;
        for(long long i=0;i<n;i++) points.push_back((r[i]-1)*r[i]/2 + c[i]);
        sort(points.begin(), points.end());
        long long current = 1;
        long long cost = 0;
        for(long long p : points){
            while(current != p){
                if((current%(long long(sqrt(2*current)) + 1))%2 == 0){
                    current++;
                }
                else{
                    current += 1 + (long long(sqrt(8*current - 7)))/2;
                }
                cost++;
            }
            current = p;
        }
        cout << cost << "\n";
    }
}