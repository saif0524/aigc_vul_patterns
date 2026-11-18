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

typedef long long ll;
typedef pair<ll, int> pii;

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    vector<pii> stools, pencils;
    vector<int> ti(n);
    for(int i = 0; i < n; ++i){
        ll c;
        int t;
        cin >> c >> t;
        ti[i] = t;
        if(t == 1){
            stools.push_back({c, i+1});
        }
        else{
            pencils.push_back({c, i+1});
        }
    }
    sort(stools.begin(), stools.end());
    sort(pencils.begin(), pencils.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < k; ++i){
        pq.push({0, i});
    }
    for(auto &stool : stools){
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + stool.first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(stool.second);
    }
    int s = 0;
    for(auto &pencil : pencils){
        if(s >= k){
            break;
        }
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + pencil.first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(pencil.second);
        s++;
    }
    int used = k - s;
    for(int i = s; i < pencils.size(); ++i){
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + pencils[i].first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(pencils[i].second);
        used++;
        if(used >= k){
            break;
        }
    }
    vector<vector<int>> ans(k);
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        int idx = cur.second;
        vector<int> &v = ans[idx];
        reverse(v.begin(), v.end());
    }
    double total = 0;
    for(int i = 0; i < k; ++i){
        vector<int> &v = ans[i];
        total += applyDiscount(v, stools, pencils);
    }
    cout << fixed << setprecision(1) << total << "\n";
    for(int i = 0; i < k; ++i){
        auto &v = ans[i];
        cout << v.size();
        for(auto x : v){
            cout << " " << x;
        }
        cout << "\n";
    }
    return 0;
}