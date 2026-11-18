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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n, 0);
    vector<long long> diff(n+1, 0);
    vector<pair<int, pair<int, long long>>> queries;
    for(int i = 0; i < m; i++){
        int t, l, r;
        long long val;
        cin >> t >> l >> r >> val;
        if(t == 1){
            diff[l-1] += val;
            diff[r] -= val;
        } else {
            queries.push_back({i, {l-1, val}});
        }
    }
    vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = diff[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i-1] + diff[i];
    }
    for(int i = 0; i < n; i++){
        a[i] = prefix_sum[i];
    }
    vector<bool> result(queries.size(), true);
    for(int i = 0; i < queries.size(); i++){
        long long max_val = LLONG_MIN;
        for(int j = queries[i].second.first; j < n; j++){
            max_val = max(max_val, a[j] + prefix_sum[j]);
            if(j >= queries[i].second.first + 1){
                max_val = max(max_val, a[j] + prefix_sum[j-1]);
            }
            if(max_val > queries[i].second.second){
                result[i] = false;
                break;
            }
        }
    }
    bool possible = true;
    for(bool res : result){
        if(!res){
            possible = false;
            break;
        }
    }
    if(possible){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}