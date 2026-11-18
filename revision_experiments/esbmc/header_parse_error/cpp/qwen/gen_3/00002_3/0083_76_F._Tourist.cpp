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
    int N;
    cin >> N;
    vector<pair<int, int>> events(N);
    for(auto &e: events){
        cin >> e.first >> e.second;
    }
    int V;
    cin >> V;
    sort(events.begin(), events.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    });
    int ans1 = 0, last_time1 = 0, last_pos1 = 0;
    for(const auto &e: events){
        if(abs(e.first - last_pos1) <= V * (e.second - last_time1)){
            ans1++;
            last_time1 = e.second;
            last_pos1 = e.first;
        }
    }
    int ans2 = 0;
    for(int start = -200000000; start <= 200000000; start += V){
        int cnt = 0, last_time2 = 0, last_pos2 = start;
        for(const auto &e: events){
            if(abs(e.first - last_pos2) <= V * (e.second - last_time2)){
                cnt++;
                last_time2 = e.second;
                last_pos2 = e.first;
            }
        }
        ans2 = max(ans2, cnt);
    }
    cout << ans1 << " " << ans2;
}