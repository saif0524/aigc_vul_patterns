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
    vector<vector<int>> dp(n+1, vector<int>(26, 0));
    for(int i=n-1;i>=0;i--){
        dp[i] = dp[i+1];
        dp[i][s[i]-'a']++;
    }
    string ans;
    for(int i=0;i<n&&ans.size()<100;){
        int ch = -1;
        for(int j=0;j<26;j++){
            if(dp[i][j] > 1){
                ch = j;
                break;
            }
        }
        if(ch != -1){
            ans += char(ch+'a');
            i++;
            while(s[i] != char(ch+'a')) i++;
            i++;
        }
        else{
            for(int j=0;j<26;j++){
                if(dp[i][j] > 0){
                    ch = j;
                    break;
                }
            }
            if(ch != -1){
                ans += char(ch+'a');
                i++;
            }
            else break;
        }
    }
    int len = ans.size();
    if(len >= 100) cout << ans.substr(0,100);
    else{
        string rev = ans;
        reverse(rev.begin(), rev.end());
        ans += rev.substr(len-1);
        cout << ans;
    }
}