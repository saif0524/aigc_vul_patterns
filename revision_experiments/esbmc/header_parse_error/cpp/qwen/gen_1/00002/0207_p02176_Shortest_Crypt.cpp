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
    int N;
    string S;
    cin >> N >> S;
    int dx=0, dy=0;
    for(char c:S){
        if(c>='A'&&c<='M') dy++;
        else if(c>='N'&&c<='Z') dy--;
        else if(c>='a'&&c<='m') dx++;
        else if(c>='n'&&c<='z') dx--;
    }
    string ans="";
    for(int i=0;i<abs(dy);i++){
        if(dy>0) ans+='A';
        else ans+='N';
    }
    for(int i=0;i<abs(dx);i++){
        if(dx>0) ans+='a';
        else ans+='n';
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
}