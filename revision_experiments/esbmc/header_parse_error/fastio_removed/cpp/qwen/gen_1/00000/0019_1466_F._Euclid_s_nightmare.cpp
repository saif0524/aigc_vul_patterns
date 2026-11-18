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

const int MOD = 1e9 + 7;

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vecs(n);
    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        vecs[i].resize(k);
        for(int &x : vecs[i]){
            cin >> x;
            --x;
        }
    }

    vector<int> chosen;
    set<int> dim_used;
    for(int i = 0; i < n; ++i){
        if(dim_used.count(vecs[i][0])){
            if(!dim_used.count(vecs[i].back())){
                int d0 = vecs[i][0];
                int d1 = vecs[i].back();
                for(int j = 0; j < n; ++j){
                    if((vecs[j].size() == 2) && (vecs[j][0] == d0) && (vecs[j].back() == d1)){
                        chosen.push_back(j);
                        dim_used.insert(d0);
                        dim_used.insert(d1);
                    }
                }
            }
        }
        else{
            chosen.push_back(i);
            dim_used.insert(vecs[i][0]);
            if(vecs[i].size() > 1){
                dim_used.insert(vecs[i].back());
            }
        }
    }
    int total_vectors = (1LL << (int)dim_used.size()) % MOD;
    cout << total_vectors << " " << chosen.size() << "\n";
    for(int i = 0; i < chosen.size(); ++i){
        if(i > 0) cout << " ";
        cout << chosen[i]+1;
    }
    cout << "\n";
}