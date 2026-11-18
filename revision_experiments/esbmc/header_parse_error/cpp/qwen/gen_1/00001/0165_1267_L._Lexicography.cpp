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
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> words(n, string(l, 'z'));
    int total = n * l;
    for(int i = 0; i < total; ++i){
        int pos = i / l;
        if(pos >= k-1){
            words[pos][i % l] = s[i];
        }
        else{
            int rem = total - (pos + 1) * l;
            if(rem < k - pos - 1){
                words[pos][i % l] = s[i];
            }
            else{
                if(s[i] < words[pos+1][i % l]){
                    words[pos][i % l] = s[i];
                }
                else{
                    words[pos+1][i % l] = min(words[pos+1][i % l], s[i]);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << words[i] << "\n";
    }
}