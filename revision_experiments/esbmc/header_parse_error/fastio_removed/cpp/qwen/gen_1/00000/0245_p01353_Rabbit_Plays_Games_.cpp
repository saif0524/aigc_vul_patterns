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
    long long n;
    cin >> n;
    vector<vector<long long>> enemies(n);
    for(int i=0;i<n;i++){
        long long h, a, d, s;
        cin >> h >> a >> d >> s;
        enemies[i] = {s, a, d, h};
    }
    long long h, a, d, s;
    cin >> h >> a >> d >> s;
    sort(enemies.rbegin(), enemies.rend());
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    long long totalDamage = 0;
    for(int i=0;i<n;i++){
        long long s_e = enemies[i][0];
        long long a_e = enemies[i][1];
        long long d_e = enemies[i][2];
        long long h_e = enemies[i][3];
        while(!pq.empty() && pq.top().first < s_e){
            totalDamage += max(0LL, a - pq.top().second);
            h -= max(0LL, pq.top().first - d);
            if(h <= 0){
                cout << -1;
                return 0;
            }
            pq.pop();
        }
        long long damage = max(0LL, a_e - d);
        h -= damage;
        if(h <= 0){
            cout << -1;
            return 0;
        }
        pq.push({s_e, d_e});
    }
    while(!pq.empty()){
        totalDamage += max(0LL, a - pq.top().second);
        h -= max(0LL, pq.top().first - d);
        if(h <= 0){
            cout << -1;
            return 0;
        }
        pq.pop();
    }
    cout << totalDamage;
}