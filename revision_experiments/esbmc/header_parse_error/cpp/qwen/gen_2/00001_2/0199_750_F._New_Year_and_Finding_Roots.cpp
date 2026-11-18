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

void ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

vector<int> read_neighbors() {
    int k;
    cin >> k;
    if (k == 0) exit(0);
    vector<int> neighbors(k);
    for (int& t : neighbors) cin >> t;
    return neighbors;
}

int find_root(int h) {
    int n = (1 << h) - 1;
    map<int, vector<int>> adjacency;

    auto query_and_store = [&](int x) {
        ask(x);
        auto neighbors = read_neighbors();
        adjacency[x] = neighbors;
        for (int y : neighbors) {
            adjacency[y].push_back(x);
        }
    };

    query_and_store(1);

    if (adjacency[1].size() == 2) return 1;

    for (int i = 2; i <= n; ++i) {
        if (adjacency.count(i) == 0) {
            query_and_store(i);
        }
        if (adjacency[i].size() == 2) return i;
    }

    for (int i = 2; i <= n; ++i) {
        if (adjacency[i].size() != 2) {
            for (int j = 0; j < adjacency[i].size(); ++j) {
                int x = adjacency[i][j];
                if (adjacency[x].size() != 2) {
                    return x;
                }
            }
        }
    }

    return -1; // Should not reach here
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int h;
        cin >> h;
        if(h == 0) break;
        int root = find_root(h);
        cout << "! " << root << endl;
        fflush(stdout);
    }
    return 0;
}