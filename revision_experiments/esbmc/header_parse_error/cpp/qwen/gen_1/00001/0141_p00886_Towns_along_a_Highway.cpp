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

vector<int> ds;
int N;

bool check(vector<int>& path) {
    vector<int> dist(N * N, 0);
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            dist[i * N + j] = dist[i * N + (i + 1)] + path[i];
        }
    }
    sort(dist.begin(), dist.end(), greater<int>());
    for (int i = 0; i < ds.size(); ++i) {
        if (dist[i] != ds[i]) return false;
    }
    return true;
}

void backtrack(vector<int>& path, int start, int sum) {
    if (path.size() == N - 1) {
        if (check(path)) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = start; i <= 400; ++i) {
        path.push_back(i);
        backtrack(path, i, sum + i);
        path.pop_back();
    }
}

int main(){
    while(cin >> N){
        if(N==0) break;
        ds.clear();
        int total_dist = N * (N - 1) / 2;
        for(int i=0;i<total_dist;i++){
            int d;
            cin >> d;
            ds.push_back(d);
        }
        sort(ds.begin(), ds.end(), greater<int>());
        vector<int> path;
        backtrack(path, 1, 0);
        cout << "-----\n";
    }
}