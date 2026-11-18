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

int dx[] = {-2, -1, 0, 1, 2};
int dy[] = {-2, -1, 0, 1, 2};

bool canSatisfy(int N, vector<vector<int>>& schedule) {
    vector<vector<int>> rain(4, vector<int>(4, 1));
    rain[1][1] = rain[1][2] = rain[2][1] = rain[2][2] = 1;

    for (int day = 1; day < N; ++day) {
        bool valid = false;
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                bool possible = true;
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        int nx = x + dx[i];
                        int ny = y + dy[j];
                        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                            if (schedule[day][nx * 4 + ny] && (abs(nx - x) > 1 || abs(ny - y) > 1)) {
                                possible = false;
                            }
                        }
                    }
                }
                if (possible) {
                    valid = true;
                    rain = vector<vector<int>>(4, vector<int>(4, 0));
                    for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                            int nx = x + dx[i];
                            int ny = y + dy[j];
                            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                                rain[nx][ny] = 1;
                            }
                        }
                    }
                    break;
                }
            }
            if (valid) break;
        }
        if (!valid) return false;
    }

    return true;
}

int main(){
    ((void)0);
    ((void)0);
    while(true){
        int N;
        cin >> N;
        if(N == 0) break;
        vector<vector<int>> schedule(N, vector<int>(16));
        for(int i=0;i<N;i++){
            for(int j=0;j<16;j++){
                cin >> schedule[i][j];
            }
        }
        if(canSatisfy(N, schedule)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}