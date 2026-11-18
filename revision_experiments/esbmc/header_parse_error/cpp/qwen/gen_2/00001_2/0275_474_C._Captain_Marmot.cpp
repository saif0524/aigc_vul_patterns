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

pair<int, int> rotate90cw(pair<int, int> p, pair<int, int> center) {
    int x = p.first - center.first;
    int y = p.second - center.second;
    return {center.first + y, center.second - x};
}

pair<int, int> rotate90ccw(pair<int, int> p, pair<int, int> center) {
    int x = p.first - center.first;
    int y = p.second - center.second;
    return {center.first - y, center.second + x};
}

bool checkSquare(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());
    for (int i = 0; i < 4; i++) {
        pair<int, int> d1 = {points[(i+1)%4].first - points[i].first, points[(i+1)%4].second - points[i].second};
        pair<int, int> d2 = {points[(i+2)%4].first - points[i].first, points[(i+2)%4].second - points[i].second};
        pair<int, int> d3 = {points[(i+3)%4].first - points[i].first, points[(i+3)%4].second - points[i].second};
        if (d1.first * d2.first + d1.second * d2.second == 0 && d3.first * d2.first + d3.second * d2.second == 0 && abs(d1.first) == abs(d2.first) && abs(d1.second) == abs(d2.second)) {
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        vector<pair<int, int>> initial(4);
        vector<pair<int, int>> centers(4);
        for (int i = 0; i < 4; i++){
            cin >> initial[i].first >> initial[i].second >> centers[i].first >> centers[i].second;
        }
        int minMoves = 10;
        for (int mask = 0; mask < 16; mask++){
            vector<pair<int, int>> current = initial;
            int moves = 0;
            for (int i = 0; i < 4; i++){
                if (mask & (1 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves++;
                }
                if (mask & (2 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves += 2;
                }
                if (mask & (4 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves += 3;
                }
            }
            if (checkSquare(current)){
                minMoves = min(minMoves, moves);
            }
        }
        if (minMoves == 10){
            cout << "-1\n";
        }
        else{
            cout << minMoves << "\n";
        }
    }
}