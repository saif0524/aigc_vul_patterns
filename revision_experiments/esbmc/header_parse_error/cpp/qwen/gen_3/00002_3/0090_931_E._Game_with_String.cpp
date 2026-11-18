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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> fail(n, -1);
    int j = -1;
    for(int i = 1; i < n; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        fail[i] = j;
    }
    vector<int> cnt(n);
    j = -1;
    for(int i = 0; i < n; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        if(j == n - 1){
            cnt[0]++;
            j = fail[j];
        }
    }
    j = -1;
    for(int i = 0; i < n - 1; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        if(j == n - 1){
            cnt[i - n + 1 + 1]++;
            j = fail[j];
        }
    }
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] == 0){
            ans += 1.0 / n;
        }
        else if(cnt[i] == 1){
            ans += 1.0 / n / (n - 1);
        }
    }
    cout << fixed << setprecision(15) << ans;
}