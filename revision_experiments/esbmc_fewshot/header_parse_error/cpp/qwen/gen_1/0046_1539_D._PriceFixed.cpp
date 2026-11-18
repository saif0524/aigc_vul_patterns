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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> items(n);
    for(auto &p: items){
        cin >> p.first >> p.second;
    }
    sort(items.begin(), items.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.second < b.second;
    });
    priority_queue<ll> pq;
    ll total = 0;
    ll bought = 0;
    for(const auto& p: items){
        ll need = p.first;
        ll disc = p.second;
        while(!pq.empty() && need > 0){
            ll top = pq.top();
            if(top <= need){
                bought += top;
                total += top;
                need -= top;
                pq.pop();
            }
            else{
                bought += need;
                total += need;
                pq.push(top - need);
                need = 0;
            }
            if(bought >= disc){
                total -= (bought - disc);
                bought = disc;
            }
        }
        if(need > 0){
            bought += need;
            total += 2 * need;
            if(bought >= disc){
                total -= (bought - disc);
                bought = disc;
            }
        }
        pq.push(p.first);
    }
    cout << total;
    return 0;
}