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
    string s;
    cin >> s;
    int k;
    cin >> k;
    map<char, char> forbidden;
    for(int i=0; i<k; i++){
        char a, b;
        cin >> a >> b;
        forbidden[a] = b;
        forbidden[b] = a;
    }
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        if(forbidden.count(s[i-1])){
            char other = forbidden[s[i-1]];
            if(i > 1 && s[i-2] == other){
                dp[i] = min(dp[i], dp[i-2] + 1);
            }else{
                dp[i] = min(dp[i], dp[i-1] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
}