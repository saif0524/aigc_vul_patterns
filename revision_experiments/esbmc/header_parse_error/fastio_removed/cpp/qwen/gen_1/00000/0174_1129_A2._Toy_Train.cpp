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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> candies(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        candies[a-1].push_back({b-1, i});
    }
    vector<int> min_time(n, INT_MAX);
    for(int start=0;start<n;start++){
        vector<bool> delivered(m, false);
        int current = start;
        int time = 0;
        while(true){
            for(auto& candy : candies[current]){
                if(!delivered[candy.second]){
                    delivered[candy.second] = true;
                    int dist = (candy.first - current + n) % n;
                    time += dist + 1;
                    current = candy.first;
                    break;
                }
            }
            if(all_of(delivered.begin(), delivered.end(), [](bool x){return x;})){
                break;
            }
            current = (current + 1) % n;
            time++;
        }
        min_time[start] = time;
    }
    for(int i=0;i<n;i++){
        cout << min_time[i] << " \n"[i==n-1];
    }
}