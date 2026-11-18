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
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pair<long long, long long>> front, back;
        for(int i=0;i<N;i++){
            long long K, L, R; cin >> K >> L >> R;
            if(K==1) front.emplace_back(L, R);
            else back.emplace_back(L, R);
        }
        sort(front.rbegin(), front.rend());
        sort(back.rbegin(), back.rend());
        long long ans = 0;
        long long sum = 0;
        for(int i=0, j=0;i<front.size();i++){
            sum += front[i].first;
            while(j<back.size() && back[j].first > front[i].second){
                sum += back[j++].first;
            }
            ans = max(ans, sum - (long long)i - j);
        }
        sum = 0;
        for(int j=0;j<back.size();j++){
            sum += back[j].first;
            ans = max(ans, sum - (long long)j);
        }
        cout << ans << "\n";
    }
}