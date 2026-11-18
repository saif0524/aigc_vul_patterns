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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    for(int i=0;i<n;i++) if(s[i] == '*') pos.push_back(i);
    int m = pos.size();
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            for(int k=j+1;k<m;k++){
                int d1 = pos[j] - pos[i];
                int d2 = pos[k] - pos[j];
                if(d1 == d2){
                    int next = pos[k] + d1;
                    auto it = lower_bound(pos.begin(), pos.end(), next);
                    if(it != pos.end() && *it == next){
                        cout << "yes";
                        return 0;
                    }
                }
            }
    cout << "no";
}