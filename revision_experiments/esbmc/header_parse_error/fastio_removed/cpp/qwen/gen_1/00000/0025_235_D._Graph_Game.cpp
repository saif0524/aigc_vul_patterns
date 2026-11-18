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

vector<vector<int>> adj;
vector<bool> visited;
double expect;

void calculate(int v, int size) {
    visited[v] = true;
    int sum = 0;
    vector<int> component_sizes;
    for (int u : adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            int comp_size = 1;
            stack<int> s;
            s.push(u);
            while (!s.empty()) {
                int x = s.top();
                s.pop();
                for (int w : adj[x]) {
                    if (!visited[w]) {
                        visited[w] = true;
                        s.push(w);
                        comp_size++;
                    }
                }
            }
            component_sizes.push_back(comp_size);
            sum += comp_size;
        }
    }
    expect += size;
    for (int comp_size : component_sizes) {
        calculate(u, comp_size);
    }
}

int main() {
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.assign(n, false);
    expect = 0.0;
    calculate(0, n);
    cout << fixed << setprecision(15) << expect / n;
    return 0;
}