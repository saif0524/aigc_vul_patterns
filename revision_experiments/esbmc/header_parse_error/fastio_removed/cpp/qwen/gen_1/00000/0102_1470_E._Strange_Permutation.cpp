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

vector<vector<int>> generate_permutations(const vector<int>& p, int c) {
    int n = p.size();
    set<vector<int>> s;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (r - l <= c) {
                vector<int> curr = p;
                reverse(curr.begin() + l, curr.begin() + r + 1);
                s.insert(curr);
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> p(n);
        for(int &x: p) cin >> x;
        vector<vector<int>> perms = generate_permutations(p, c);
        sort(perms.begin(), perms.end());
        while(q--){
            int i, j;
            cin >> i >> j;
            --i;
            if(j > perms.size()){
                cout << -1 << "\n";
            }
            else{
                cout << perms[j-1][i] << "\n";
            }
        }
    }
}