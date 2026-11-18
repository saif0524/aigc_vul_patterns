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
    int n, t, k;
    cin >> n >> t >> k;
    vector<vector<long long>> stations(n, vector<long long>(3, 0));
    for(int i=0; i<n; i++){
        cin >> stations[i][0] >> stations[i][1] >> stations[i][2];
    }
    int ans = 0;
    for(int hour=0; hour<t; hour++){
        vector<long long> people(n);
        for(int i=0; i<n; i++){
            people[i] = stations[i][0] + 1LL * hour * stations[i][1];
        }
        int trains = 0;
        for(int i=0; i<n; i++){
            if(people[i] > 0){
                long long capacity_needed = people[i];
                if(i > 0 && people[i-1] > 0){
                    capacity_needed -= (stations[i][2] - people[i-1]);
                }
                if(capacity_needed > 0){
                    trains += (capacity_needed + k - 1) / k;
                }
            }
        }
        ans = max(ans, trains);
    }
    cout << ans;
    return 0;
}