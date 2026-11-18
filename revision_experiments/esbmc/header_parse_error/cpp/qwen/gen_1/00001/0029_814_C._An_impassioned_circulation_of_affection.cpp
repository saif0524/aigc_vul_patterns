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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<pair<int, char>> queries(q);
    for(auto &x: queries){
        cin >> x.first >> x.second;
    }
    for(auto &[m, c]: queries){
        int maxkoyomity = 0;
        int left = 0, right = 0, repaints = 0;
        while(right < n){
            if(s[right] == c){
                right++;
            }
            else if(repaints < m){
                right++;
                repaints++;
            }
            else{
                maxkoyomity = max(maxkoyomity, right - left);
                if(s[left] != c){
                    repaints--;
                }
                left++;
            }
        }
        maxkoyomity = max(maxkoyomity, right - left);
        cout << maxkoyomity << "\n";
    }
}