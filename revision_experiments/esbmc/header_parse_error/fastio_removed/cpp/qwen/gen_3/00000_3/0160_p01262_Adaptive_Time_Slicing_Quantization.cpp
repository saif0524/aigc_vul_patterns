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

double calc_error(vector<double>& frame, int L) {
    double Vmin = *min_element(frame.begin(), frame.end());
    double Vmax = *max_element(frame.begin(), frame.end());
    double step = (Vmax - Vmin) / (2 * L - 1);
    double error = 0.0;
    for (double v : frame) {
        int idx = round((v - Vmin) / step);
        double quantized = Vmin + idx * step;
        error += (v - quantized) * (v - quantized);
    }
    return error;
}

int main(){
    ((void)0);
    ((void)0);
    int N, M, L;
    while(cin >> N >> M >> L && N && M && L){
        vector<double> V(N);
        for(auto& v : V) cin >> v;
        vector<vector<double>> frames(M);
        vector<double> best_error(M, 1e18);
        function<void(int, int)> dfs = [&](int i, int frame_id){
            if(i == N){
                if(frame_id == M){
                    double total_error = 0;
                    for(int j = 0; j < M; j++){
                        total_error += calc_error(frames[j], L);
                    }
                    best_error[M-1] = min(best_error[M-1], total_error);
                }
                return;
            }
            if(i >= 2){
                frames[frame_id].push_back(V[i]);
                dfs(i+1, frame_id);
                frames[frame_id].pop_back();
            }
            if(frame_id + 1 < M){
                frames[frame_id+1].push_back(V[i]);
                dfs(i+1, frame_id+1);
                frames[frame_id+1].pop_back();
            }
        };
        frames[0].push_back(V[0]);
        frames[0].push_back(V[1]);
        dfs(2,0);
        cout << fixed << setprecision(10) << best_error[M-1] << "\n";
    }
}