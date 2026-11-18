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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> subsets(k);
    vector<vector<int>> pos(n+1);
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        for(int j=0;j<c;j++){
            int x;
            cin >> x;
            subsets[i].push_back(x);
            pos[x].push_back(i);
        }
    }
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    vector<int> switches(n+1);
    vector<int> last(k,-1);
    for(int i=1;i<=n;i++){
        int state = s[i-1]-'0';
        if(pos[i].size()==2){
            for(int id : pos[i]){
                int j = last[id];
                if(j!=-1){
                    dp[i] = min(dp[i],dp[j]^1);
                    switches[i] = switches[j]^1;
                }
            }
        }
        dp[i] = min(dp[i],dp[i-1]);
        switches[i] = switches[i-1];
        for(int id : pos[i]){
            last[id] = i;
        }
        int need = 1^state;
        if(switches[i]==need){
            dp[i] = min(dp[i],dp[i-1]+1);
        }
        if(pos[i].size()==1){
            int id = pos[i][0];
            int j = last[id];
            if(j!=-1){
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dp[i] << "\n";
    }
}