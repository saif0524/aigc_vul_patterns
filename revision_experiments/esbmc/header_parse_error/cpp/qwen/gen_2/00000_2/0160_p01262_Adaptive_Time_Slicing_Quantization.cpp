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

double dp[257][129];
double best[257][129];

double quantize(vector<double>& seq, int start, int m, int l) {
    if (start == seq.size()) return 0.0;
    if (m == 0) return 1e18;
    if (dp[start][m] != -1) return dp[start][m];
    
    double res = 1e18;
    for (int i = start + 1; i <= seq.size() - m + 1; ++i) {
        double vmax = *max_element(seq.begin() + start, seq.begin() + i);
        double vmin = *min_element(seq.begin() + start, seq.begin() + i);
        double step = (vmax - vmin) / (1 << l);
        
        double sum_sq_err = 0.0;
        for (int j = start; j < i; ++j) {
            int idx = round((seq[j] - vmin) / step);
            idx = max(0, min((1 << l) - 1, idx));
            double qval = vmin + idx * step;
            sum_sq_err += (seq[j] - qval) * (seq[j] - qval);
        }
        
        res = min(res, sum_sq_err + quantize(seq, i, m - 1, l));
    }
    
    dp[start][m] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, L;
    while(cin >> N >> M >> L){
        if(N==0 && M==0 && L==0) break;
        vector<double> seq(N);
        for(double &x : seq) cin >> x;
        
        memset(dp, -1, sizeof(dp));
        cout << fixed << setprecision(6) << quantize(seq, 0, M, L) << '\n';
    }
}