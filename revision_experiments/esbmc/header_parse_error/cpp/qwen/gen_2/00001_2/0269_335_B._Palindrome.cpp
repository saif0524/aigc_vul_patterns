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
    vector<vector<int>> next(n, vector<int>(26, -1));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            if(i+1 < n) next[i][j] = next[i+1][j];
        }
        next[i][s[i] - 'a'] = i;
    }
    vector<int> lps(101, -1);
    int len = 0, i = 0;
    string palin = "";
    while(i < n && len < 100){
        int j = s[i] - 'a';
        if(i == 0 && next[i][j] >= 0){
            len = 1;
            palin += s[i];
            i = next[i][j] + 1;
        }
        else if(next[i][j] > lps[len]){
            len++;
            palin += s[i];
            lps[len] = next[i][j];
            i = next[i][j] + 1;
        }
        else{
            i++;
        }
    }
    if(len < 100){
        string half_pal = "";
        i = 0;
        vector<int> used_chars(26, 0);
        while(i < n){
            int j = s[i] - 'a';
            if(used_chars[j] == 0){
                half_pal += s[i];
                used_chars[j] = 1;
            }
            i = next[i][j] + 1;
        }
        palin = "";
        int left = 0, right = half_pal.size() - 1;
        while(left <= right){
            palin += half_pal[left];
            if(left != right) palin += half_pal[right];
            left++;
            right--;
        }
    }
    else{
        string second_half = "";
        for(int i = 1; i <= 50; i++){
            second_half += palin[99 - i];
        }
        palin += second_half;
    }
    int target_len = (len >= 100) ? 100 : palin.length() / 2;
    cout << palin.substr(0, target_len);
    if(len < 100){
        reverse(palin.begin(), palin.end());
        cout << palin.substr(0, target_len);
    }
}