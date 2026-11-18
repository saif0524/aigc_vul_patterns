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

double dp[257][17][129];
double min_error[257][129];
double arr[257];

double getQuantizedValue(double v, double vmin, double vmax, int L) {
    double step = (vmax - vmin) / (1LL << L - 1);
    return vmin + round((v - vmin) / step) * step;
}

double calculateError(int start, int end, int L) {
    double vmin = *min_element(arr + start, arr + end + 1);
    double vmax = *max_element(arr + start, arr + end + 1);
    double error = 0.0;
    for (int i = start; i <= end; ++i) {
        double qv = getQuantizedValue(arr[i], vmin, vmax, L);
        error += (qv - arr[i]) * (qv - arr[i]);
    }
    return error;
}

int main(){
    ((void)0);
    ((void)0);
    int N, M, L;
    while(cin >> N >> M >> L){
        if(N == 0 && M == 0 && L == 0) break;
        for(int i=0;i<N;i++) cin >> arr[i];
        
        for(int i=0;i<N;i++){
            for(int j=1;j<=L;j++){
                min_error[i][j] = calculateError(0, i, j);
                for(int k=1;k<i;k++){
                    min_error[i][j] = min(min_error[i][j], min_error[k][j-1] + calculateError(k+1, i, j));
                }
            }
        }
        
        cout << fixed << setprecision(7) << min_error[N-1][M] << "\n";
    }
    return 0;
}