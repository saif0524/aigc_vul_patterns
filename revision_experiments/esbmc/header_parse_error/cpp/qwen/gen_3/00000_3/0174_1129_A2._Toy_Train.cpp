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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> candies(m);
    for(auto &x: candies){
        cin >> x.first >> x.second;
        if(x.first > x.second) x.second += n;
    }
    vector<vector<int>> events(n+1);
    for(const auto &x: candies){
        int start = x.first;
        int end = x.second;
        events[start].push_back(end);
    }
    vector<int> result(n+1, 0);
    for(int start = 1; start <= n; ++start){
        int currentTime = 0;
        for(int i = start; i <= start + n - 1; ++i){
            int station = i > n ? i - n : i;
            int nextStation = station == n ? 1 : station + 1;
            for(auto end: events[station]){
                if(end >= i){
                    currentTime = max(currentTime, end);
                }
            }
            currentTime++;
        }
        result[start] = currentTime - 1;
    }
    for(int i = 1; i <= n; ++i){
        if(i > 1) cout << " ";
        cout << result[i];
    }
    cout << "\n";
}