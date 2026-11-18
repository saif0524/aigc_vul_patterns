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
        long long N;
        cin >> N;
        vector<vector<long long>> camels(N, vector<long long>(3));
        for(auto &c: camels){
            cin >> c[0] >> c[1] >> c[2];
        }
        sort(camels.begin(), camels.end(), [](const vector<long long>& a, const vector<long long>& b){
            return a[1] - a[2] > b[1] - b[2];
        });
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        long long ans = 0, sum = 0;
        for(int i=0; i<N; i++){
            long long K = camels[i][0], L = camels[i][1], R = camels[i][2];
            sum += L;
            pq.push({K, L});
            if(pq.size() > K){
                sum -= pq.top().second;
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans += sum;
            auto top = pq.top();
            pq.pop();
            sum -= top.second;
        }
        cout << ans << "\n";
    }
}