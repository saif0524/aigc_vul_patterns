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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(auto &x : a) { cin >> x; }
    sort(a.begin(), a.end());
    int total_games = (1<<(n+1)) - 2;
    vector<bool> fans(1<<(n+1), false);
    for(auto x : a) { fans[x] = true; }
    auto can_win = [&](int x){
        if(x > (1<<n)) return true;
        if(fans[x]) return true;
        return false;
    };
    int result = 0;
    for(int game = 1; game <= total_games; ++game){
        int winner = 0, loser = 0;
        if(game <= (1<<n) - 1){
            winner = 2*game;
            loser = 2*game + 1;
        }
        else{
            int diff = game - ((1<<n) - 1);
            int lower = 1 + (1<<n) + (diff-1)/2;
            int upper = ((1<<n) - (diff & 1) - (diff>>1)) / 2 + 1;
            if(diff & 1){
                winner = lower;
                loser = upper;
            }
            else{
                winner = upper;
                loser = lower;
            }
        }
        result += fans[winner] || fans[loser];
        fans[winner] = fans[winner] || fans[loser];
    }
    cout << result;
}