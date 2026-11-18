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

bool can_eat(vector<long long>& q, deque<pair<int, long long>>& rem) {
    while (!rem.empty()) {
        if (q.front() > rem.front().second) {
            q.front() += rem.front().second;
            rem.pop_front();
        } else if (q.back() > rem.back().second) {
            q.back() += rem.back().second;
            rem.pop_back();
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    int n, k;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    cin >> k;
    vector<long long> b(k);
    for(auto &x: b) cin >> x;

    deque<pair<int, long long>> rem;
    for(int i=n-1;i>=k;i--) rem.push_front({i+1, a[i]});
    for(int i=0;i<k;i++){
        while(!rem.empty() && rem.front().second + q.front() <= b[i]) {
            q.push_back(rem.front().second + q.front());
            cout << rem.front().first << " L" << endl;
            rem.pop_front();
            q.pop_front();
        }
        if(!rem.empty()){
            if(q.front() > rem.front().second && q.front() + rem.front().second == b[i]){
                cout << rem.front().first << " L" << endl;
                rem.pop_front();
                q.pop_front();
                q.push_back(b[i]);
            } else {
                cout << "NO";
                return 0;
            }
        } else {
            q.push_back(b[i]);
        }
    }
    if(!rem.empty()){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}