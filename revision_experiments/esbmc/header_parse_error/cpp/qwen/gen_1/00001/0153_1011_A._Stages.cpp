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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> weights;
    for(char c : s){
        weights.push_back(c - 'a' + 1);
    }
    sort(weights.begin(), weights.end());
    int ans = INT_MAX;
    for(int i = 0; i <= n - k; i++){
        bool valid = true;
        int current_weight = weights[i];
        int last = weights[i];
        int count = 1;
        for(int j = i + 1; j < n && count < k; j++){
            if(weights[j] - last >= 2){
                last = weights[j];
                current_weight += weights[j];
                count++;
            }
        }
        if(count == k){
            ans = min(ans, current_weight);
        }
    }
    if(ans == INT_MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
}