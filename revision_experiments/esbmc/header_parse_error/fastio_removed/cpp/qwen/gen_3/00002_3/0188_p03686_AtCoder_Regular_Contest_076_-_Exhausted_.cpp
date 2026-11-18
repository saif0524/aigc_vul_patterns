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
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> ranges(N);
    for(auto &r: ranges) cin >> r.first >> r.second;
    sort(ranges.begin(), ranges.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    for(int j=1;j<=M+1;j++){
        while(i < N && ranges[i].first <= j) {
            pq.push(ranges[i].second);
            i++;
        }
        while(!pq.empty() && pq.top() < j) pq.pop();
        if(!pq.empty()){
            pq.pop();
        } else {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}