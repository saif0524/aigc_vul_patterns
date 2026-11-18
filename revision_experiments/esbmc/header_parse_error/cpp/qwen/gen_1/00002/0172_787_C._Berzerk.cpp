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
    int k1;
    cin >> k1;
    vector<int> s1(k1);
    for(auto &x: s1) cin >> x;
    int k2;
    cin >> k2;
    vector<int> s2(k2);
    for(auto &x: s2) cin >> x;

    vector<vector<int>> moves(n, vector<int>(2, -1)); // -1 = not visited, 0 = lose, 1 = win, 2 = loop
    vector<int> steps = {k1, k2};
    vector<vector<int>> strategies = {s1, s2};

    function<int(int,int)> dfs = [&](int pos, int player){
        int &result = moves[pos][player];
        if(result != -1) return result;
        for(auto move: strategies[player]){
            int next_pos = (pos + move) % n;
            if(next_pos == 0){
                return result = 1;
            }
            int opponent_result = dfs(next_pos, 1 - player);
            if(opponent_result == 0){
                return result = 1;
            }
        }
        for(auto move: strategies[player]){
            int next_pos = (pos + move) % n;
            int opponent_result = dfs(next_pos, 1 - player);
            if(opponent_result == 1){
                continue;
            }
            else if(opponent_result == -1){
                return result = 2;
            }
        }
        return result = 0;
    };

    for(int i = 1; i < n; i++){
        int result = dfs(i, 0);
        if(result == 0) cout << "Lose ";
        else if(result == 1) cout << "Win ";
        else cout << "Loop ";
    }
    cout << endl;
    for(int i = 1; i < n; i++){
        int result = dfs(i, 1);
        if(result == 0) cout << "Lose ";
        else if(result == 1) cout << "Win ";
        else cout << "Loop ";
    }
    cout << endl;

    return 0;
}