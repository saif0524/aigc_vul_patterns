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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<vector<int>> A(p, vector<int>(p));
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cin >> A[i][j];
        }
    }
    vector<int> freq(p, 0);
    for(char c : s){
        freq[c - 'a']++;
    }
    vector<bool> valid(p, true);
    int ans = n;
    for(int mask=1;mask<(1<<p);mask++){
        vector<bool> can_connect(p, false);
        vector<int> selected;
        int cnt = 0;
        for(int i=0;i<p;i++){
            if(mask & (1<<i)){
                cnt++;
                selected.push_back(i);
                if(freq[i] == 0){
                    can_connect[i] = true;
                    continue;
                }
            }
        }
        if(cnt == 0){
            continue;
        }
        can_connect[selected[0]] = true;
        bool ok = true;
        for(int i=1;i<cnt;i++){
            bool found = false;
            for(int j=0;j<i;j++){
                if(A[selected[i]][selected[j]] || A[selected[j]][selected[i]]){
                    can_connect[selected[i]] = true;
                    found = true;
                    break;
                }
            }
            if(!found){
                ok = false;
                break;
            }
        }
        if(!ok){
            continue;
        }
        int current_length = 0;
        for(int i=0;i<p;i++){
            if(can_connect[i]){
                current_length += freq[i];
            }
        }
        ans = min(ans, current_length);
    }
    cout << ans;
}