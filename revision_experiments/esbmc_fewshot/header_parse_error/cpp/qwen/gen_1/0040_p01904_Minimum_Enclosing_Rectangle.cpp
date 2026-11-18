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

struct Point {
    long long x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Point> points(N);
    points[0] = {0, 0};
    long long minX = 0, maxX = 0, minY =0, maxY = 0;
    
    for(int i=1; i<N; ++i){
        int n_i, d_i;
        cin >> n_i >> d_i;
        Point prev = points[n_i];
        Point curr;
        if(d_i == 0){
            curr.x = prev.x - 1;
            curr.y = prev.y;
        }
        else if(d_i == 1){
            curr.x = prev.x;
            curr.y = prev.y - 1;
        }
        else if(d_i == 2){
            curr.x = prev.x + 1;
            curr.y = prev.y;
        }
        else{
            curr.x = prev.x;
            curr.y = prev.y + 1;
        }
        points[i] = curr;
        minX = min(minX, curr.x);
        maxX = max(maxX, curr.x);
        minY = min(minY, curr.y);
        maxY = max(maxY, curr.y);
    }
    
    long long width = maxX - minX + 1;
    long long height = maxY - minY + 1;
    cout << width * height;
    return 0;
}