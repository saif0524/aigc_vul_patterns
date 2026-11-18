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
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> c[i];
    int d;
    cin >> d;
    vector<int> l(d);
    for(int i=0; i<d; i++) cin >> l[i];
    vector<vector<int>> clubs(m);
    vector<int> mex(m, 0);
    vector<set<int>> club_students(m);
    for(int i=0; i<n; i++){
        clubs[c[i]-1].push_back(i);
        club_students[c[i]-1].insert(p[i]);
    }
    for(int i=0; i<m; i++){
        while(club_students[i].count(mex[i])){
            mex[i]++;
        }
    }
    vector<int> ans(d, 0);
    for(int i=0; i<d; i++){
        int student = l[i] - 1;
        int club = c[student] - 1;
        club_students[club].erase(p[student]);
        while(club_students[club].count(mex[club])){
            mex[club]++;
        }
        set<int> current_mex;
        for(int j=0; j<m; j++){
            if(!club_students[j].empty()){
                current_mex.insert(mex[j]);
            }
        }
        if(!current_mex.empty()){
            ans[i] = *current_mex.begin();
        }
    }
    for(int i=0; i<d; i++) cout << ans[i] << (i < d-1 ? "\n" : "");
}