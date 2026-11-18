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

vector<vector<int>> permutations;

void generate_permutations(int n, vector<int> &arr, int c) {
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n && r - l <= c; ++r) {
            auto copy = arr;
            reverse(copy.begin() + l, copy.begin() + r + 1);
            permutations.push_back(copy);
        }
    }
    sort(permutations.begin(), permutations.end());
    permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> arr(n);
        for(int &x : arr) cin >> x;
        permutations.clear();
        generate_permutations(n, arr, c);
        while(q--){
            int i, j;
            cin >> i >> j;
            j--; // Convert to 0-based index
            if(j >= (int)permutations.size()){
                cout << -1 << "\n";
            }
            else{
                cout << permutations[j][i-1] << "\n";
            }
        }
    }
}