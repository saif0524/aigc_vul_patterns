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
    vector<vector<int>> from(n), to(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        from[a].push_back(b);
    }
    vector<int> res(n, 0);
    for(int start=0; start<n; start++){
        vector<int> dp(n, INT_MAX);
        dp[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while(!pq.empty()){
            int time = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            if(dp[pos] < time){
                continue;
            }
            for(int next: from[pos]){
                int nt = time + (next >= pos ? next - pos : n - pos + next);
                if(nt < dp[next]){
                    dp[next] = nt;
                    pq.push({nt, next});
                }
            }
            int prev = (pos == 0 ? n-1 : pos-1);
            int nt = time + (pos >= prev ? pos - prev : n - prev + pos);
            if(nt < dp[prev]){
                dp[prev] = nt;
                pq.push({nt, prev});
            }
        }
        int total = 0;
        for(int i=0; i<n; i++){
            total += dp[i];
        }
        res[start] = total;
    }
    for(int i=0; i<n; i++){
        if(i > 0) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
    return 0;
}