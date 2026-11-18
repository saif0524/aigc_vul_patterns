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

vector<string> words;
string ans;
int n, m;
ll K;

bool possible(ll len) {
    static vector<ll> dp(2020, 0);
    dp[0] = 1;
    for (int i = 1; i <= len; ++i) {
        dp[i] = 0;
        for (auto &w : words) {
            if (i >= (int)w.size()) {
                dp[i] += dp[i - (int)w.size()];
            }
        }
    }
    return dp[len] >= K;
}

void construct(int len) {
    if (len == 0) return;
    ll cnt = 0;
    for (auto &w : words) {
        if (len >= (int)w.size()) {
            cnt += possible(len - (int)w.size());
            if (cnt >= K) {
                ans += w;
                construct(len - (int)w.size());
                return;
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m >> K;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(), words.end());
    if(possible(m)){
        construct(m);
        cout << ans;
    }else{
        cout << "-";
    }
}