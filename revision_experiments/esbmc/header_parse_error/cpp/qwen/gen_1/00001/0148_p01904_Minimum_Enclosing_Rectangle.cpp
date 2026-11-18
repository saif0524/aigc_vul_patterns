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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> pos(N);
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    for(int i=1; i<N; i++){
        int n_i, d_i;
        cin >> n_i >> d_i;
        if(d_i == 0){
            pos[i] = {pos[n_i].first-1, pos[n_i].second};
            minX = min(minX, pos[i].first);
        }
        else if(d_i == 1){
            pos[i] = {pos[n_i].first, pos[n_i].second-1};
            minY = min(minY, pos[i].second);
        }
        else if(d_i == 2){
            pos[i] = {pos[n_i].first+1, pos[n_i].second};
            maxX = max(maxX, pos[i].first);
        }
        else{
            pos[i] = {pos[n_i].first, pos[n_i].second+1};
            maxY = max(maxY, pos[i].second);
        }
    }
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    cout << width * height;
}