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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int l = 0, r = n-1;
    vector<int> ans;
    vector<char> moves;
    while(l <= r){
        if(l == r){
            ans.push_back(a[l]);
            moves.push_back('L');
            break;
        }
        if(a[l] < a[r]){
            ans.push_back(a[l]);
            moves.push_back('L');
            l++;
        }
        else if(a[r] < a[l]){
            ans.push_back(a[r]);
            moves.push_back('R');
            r--;
        }
        else{
            int len1 = 0, len2 = 0;
            int l1 = l, r1 = r;
            while(l1 < r1 && a[l1] < a[l1+1]) len1++, l1++;
            while(l1 < r1 && a[r1] > a[r1-1]) len1++, r1--;
            l1 = l, r1 = r;
            while(l1 < r1 && a[r1] < a[r1-1]) len2++, r1--;
            while(l1 < r1 && a[l1] > a[l1+1]) len2++, l1++;
            if(len1 >= len2){
                ans.push_back(a[l]);
                moves.push_back('L');
                l++;
            }
            else{
                ans.push_back(a[r]);
                moves.push_back('R');
                r--;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto &x: moves) cout << x;
    cout << "\n";
}