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
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<vector<long long>> camels(N, vector<long long>(3));
        for(int i=0;i<N;i++){
            cin >> camels[i][0] >> camels[i][1] >> camels[i][2];
        }
        sort(camels.begin(), camels.end(), [](const vector<long long>& a, const vector<long long>& b){
            return a[1] > b[1];
        });
        long long total_happiness = 0;
        long long sum_R = 0;
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        for(int i=0;i<N;i++){
            if(i < camels[i][0]){
                total_happiness += camels[i][1];
                min_heap.push(camels[i][1]);
                sum_R += camels[i][1];
            }
            else{
                if(min_heap.top() < camels[i][2]){
                    sum_R -= min_heap.top();
                    min_heap.pop();
                    total_happiness -= min_heap.top();
                    min_heap.push(camels[i][2]);
                    sum_R += camels[i][2];
                    total_happiness += camels[i][2];
                }
            }
        }
        cout << total_happiness << '\n';
    }
}