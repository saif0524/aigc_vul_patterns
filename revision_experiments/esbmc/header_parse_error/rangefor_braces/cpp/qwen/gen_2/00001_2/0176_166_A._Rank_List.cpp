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
    vector<pair<int, int>> teams(n);
    for(auto &t : teams) { cin >> t.first >> t.second; }
    sort(teams.begin(), teams.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    int rank = 1, cnt = 1;
    for(int i = 1; i < n; ++i){
        if(teams[i] == teams[i-1]) cnt++;
        else{
            if(rank == k) break;
            rank += cnt;
            cnt = 1;
        }
    }
    if(rank == k || (rank + cnt > k && rank <= k)) cout << cnt;
    else cout << 0;
}