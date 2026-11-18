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
    ((void)0);
    ((void)0);
    int M, N, K;
    cin >> M >> N >> K;
    vector<string> grid(M);
    for(auto &row: grid) cin >> row;
    vector<vector<int>> jungle(M+1, vector<int>(N+1)), ocean(M+1, vector<int>(N+1)), ice(M+1, vector<int>(N+1));
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            jungle[i][j] = jungle[i-1][j] + jungle[i][j-1] - jungle[i-1][j-1] + (grid[i-1][j-1] == 'J');
            ocean[i][j] = ocean[i-1][j] + ocean[i][j-1] - ocean[i-1][j-1] + (grid[i-1][j-1] == 'O');
            ice[i][j] = ice[i-1][j] + ice[i][j-1] - ice[i-1][j-1] + (grid[i-1][j-1] == 'I');
        }
    }
    while(K--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << jungle[c][d] - jungle[c][b-1] - jungle[a-1][d] + jungle[a-1][b-1] << " ";
        cout << ocean[c][d] - ocean[c][b-1] - ocean[a-1][d] + ocean[a-1][b-1] << " ";
        cout << ice[c][d] - ice[c][b-1] - ice[a-1][d] + ice[a-1][b-1] << "\n";
    }
}