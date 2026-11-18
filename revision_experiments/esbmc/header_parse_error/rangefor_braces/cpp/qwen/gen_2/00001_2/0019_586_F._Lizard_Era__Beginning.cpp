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
    vector<vector<int>> tasks(n, vector<int>(3));
    for(auto& t : tasks) { cin >> t[0] >> t[1] >> t[2]; }
    
    int max_attitude = -1;
    vector<string> best_solution;
    
    for(int i = 0; i < (1<<n); ++i){
        if(__builtin_popcount(i) != n/2) continue;
        
        int l=0, m=0, w=0;
        vector<string> solution;
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                l+=tasks[j][0];
                m+=tasks[j][1];
                w+=tasks[j][2];
                solution.push_back("LM");
            } else {
                l+=tasks[j][0];
                m+=tasks[j][1];
                w+=tasks[j][2];
                solution.push_back("MW");
            }
        }
        
        if(l == m && m == w){
            if(l > max_attitude){
                max_attitude = l;
                best_solution = solution;
            }
        }
    }
    
    if(max_attitude == -1){
        cout << "Impossible";
    } else {
        for(auto& s : best_solution) { cout << s << "\n"; }
    }
    
    return 0;
}