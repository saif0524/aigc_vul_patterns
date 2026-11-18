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
    ((void)0); ((void)0);
    while(true){
        int p, s;
        cin >> p >> s;
        if(p == 0 && s == 0) break;
        vector<vector<int>> grid(p+1, vector<int>(s+1, 0));
        vector<pair<int, int>> unknowns;
        for(int i = 0; i < p; ++i){
            for(int j = 0; j <= s; ++j){
                string val;
                cin >> val;
                if(val == "?") unknowns.emplace_back(i, j);
                else grid[i][j] = stoi(val);
            }
        }
        for(int j = 0; j <= s; ++j){
            string val;
            cin >> val;
            if(val != "?") grid[p][j] = stoi(val);
        }
        vector<int> sol;
        auto solve = [&](auto self, int idx) -> bool {
            if(idx == unknowns.size()){
                for(int i = 0; i < p; ++i){
                    int sum = 0;
                    for(int j = 0; j < s; ++j) sum += grid[i][j];
                    if(sum != grid[i][s]) return false;
                }
                for(int j = 0; j <= s; ++j){
                    int sum = 0;
                    for(int i = 0; i < p; ++i) sum += grid[i][j];
                    if(sum != grid[p][j]) return false;
                }
                return true;
            }
            int r = unknowns[idx].first, c = unknowns[idx].second;
            int targetRow = grid[r][s];
            int targetCol = grid[p][c];
            int currentRow = 0, currentCol = 0;
            for(int i = 0; i < s; ++i) if(i != c) currentRow += grid[r][i];
            for(int i = 0; i < p; ++i) if(i != r) currentCol += grid[i][c];
            int diffRow = targetRow - currentRow;
            int diffCol = targetCol - currentCol;
            if(diffRow != diffCol) return false;
            grid[r][c] = diffRow;
            sol.push_back(diffRow);
            if(self(self, idx+1)) return true;
            sol.pop_back();
            return false;
        };
        if(solve(solve, 0)){
            for(int x : sol) cout << x << "\n";
        }
        else{
            cout << "NO\n";
        }
        cout << "\n";
    }
}