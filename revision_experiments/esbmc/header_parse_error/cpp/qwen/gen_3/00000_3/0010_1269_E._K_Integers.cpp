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
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<long long> f(n+1, 0);
    deque<int> dq;
    long long cost = 0;
    for(int i=0; i<n; ++i){
        dq.push_back(p[i]);
        cost += abs(p[i] - (i+1));
        if(dq.size() > i+1){
            cost -= abs(dq.front() - 1);
            dq.pop_front();
        }
        if(dq.size() == i+1){
            f[i+1] = cost;
            for(int j=0; j<i+1; ++j){
                if(dq[j] == j+1) continue;
                cost -= abs(dq[j] - (j+1));
                cost += abs(dq[j] - (i+2-j));
                swap(dq[j], dq[i+1-j-1]);
            }
        }
    }
    for(int i=1; i<=n; ++i){
        if(i>1) cout << " ";
        cout << f[i];
    }
    cout << "\n";
}