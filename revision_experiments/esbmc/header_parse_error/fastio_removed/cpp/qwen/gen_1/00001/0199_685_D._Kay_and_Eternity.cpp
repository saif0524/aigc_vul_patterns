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

const int MAXK = 302;
const int MAXN = 100005;

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> ice(n);
    for(auto &p : ice){
        cin >> p.first >> p.second;
    }
    map<long long, map<long long, int>> countMap;
    for(const auto &p : ice){
        countMap[p.first][p.second]++;
    }
    vector<int> ans(n + 1, 0);
    for(auto &[x, yMap] : countMap){
        for(auto &[y, c] : yMap){
            for(int i = 0; i < k; ++i){
                for(int j = 0; j < k; ++j){
                    long long startX = x - i;
                    long long startY = y - j;
                    long long endX = startX + k;
                    long long endY = startY + k;
                    if(countMap.count(startX) && countMap[startX].count(startY)){
                        int add = countMap[startX][startY];
                        if(endX > maxX || endY > maxY) continue;
                        ans[add]++;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}