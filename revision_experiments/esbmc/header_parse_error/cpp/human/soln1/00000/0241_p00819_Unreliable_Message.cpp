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
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF 1e8
using namespace std;
bool is_digit(char x){
    for(int i=48; i<=57; i++){
        if(x == i) return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    rep(k,n){
        string s,t;
        cin >> s >> t;
        for(int i=s.size()-1; i>=0; i--){
            //cout << t << endl;
            if(s[i] == 'J') rotate(t.rbegin(),t.rbegin()+1,t.rend());
            
            if(s[i] == 'C') rotate(t.begin(),t.begin()+1,t.end());
            if(s[i] == 'E') {
                rep(j,t.size()/2){
                    swap(t[j],t[t.size()-t.size()/2+j]);
                }
            }
            if(s[i] == 'A') reverse(t.begin(),t.end());
            if(s[i] == 'P') {
                rep(j,t.size()){
                    if(is_digit(t[j])) {
                        if(t[j] == 48) t[j] = 57;
                        else t[j]--;
                    }
                }
            }
            if(s[i] == 'M') {
                rep(j,t.size()){
                    if(is_digit(t[j])) {
                        if(t[j] == 57) t[j] = 48;
                        else t[j]++;
                    }
                }
            }
        }
        cout << t << endl;
    }
    return 0;
}