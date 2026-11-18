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
    string left_wall, right_wall;
    cin >> left_wall >> right_wall;
    vector<bool> left_safe(n+1, false), right_safe(n+1, false);
    for(int i=0;i<n;i++){
        if(left_wall[i] == '-') left_safe[i+1] = true;
        if(right_wall[i] == '-') right_safe[i+1] = true;
    }
    queue<pair<int, bool>> q;
    q.push({1, false});
    vector<vector<bool>> visited(n+1, vector<bool>(2, false));
    visited[1][false] = true;
    int time = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto [pos, wall] = q.front();
            q.pop();
            if(pos > n){
                cout << "YES";
                return 0;
            }
            if(wall && left_safe[pos] && !visited[pos][false]){
                visited[pos][false] = true;
                q.push({pos, false});
            }
            if(!wall && right_safe[pos] && !visited[pos][true]){
                visited[pos][true] = true;
                q.push({pos, true});
            }
            if(pos + 1 <= n - time && left_safe[pos+1] && !visited[pos+1][false]){
                visited[pos+1][false] = true;
                q.push({pos+1, false});
            }
            if(pos + 1 <= n - time && right_safe[pos+1] && !visited[pos+1][true]){
                visited[pos+1][true] = true;
                q.push({pos+1, true});
            }
            if(pos - 1 > 0 && left_safe[pos-1] && !visited[pos-1][false]){
                visited[pos-1][false] = true;
                q.push({pos-1, false});
            }
            if(pos - 1 > 0 && right_safe[pos-1] && !visited[pos-1][true]){
                visited[pos-1][true] = true;
                q.push({pos-1, true});
            }
            if(pos + k <= n - time && wall && right_safe[pos+k] && !visited[pos+k][true]){
                visited[pos+k][true] = true;
                q.push({pos+k, true});
            }
            if(pos + k <= n - time && !wall && left_safe[pos+k] && !visited[pos+k][false]){
                visited[pos+k][false] = true;
                q.push({pos+k, false});
            }
        }
        time++;
    }
    cout << "NO";
    return 0;
}