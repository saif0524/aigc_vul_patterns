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
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

class SCCDecomp {
    int n;
    vvi adj;
    
public:
    vvi scc;
    SCCDecomp(int n) : n(n), adj(n) {}
    
    void addArc(int a, int b) {
        adj[a].push_back(b);
    }

    int run() {
        vi num(n), low(n);
        stack<int> S;
        vi inS(n);
        int t = 0;
        function<void(int)> visit = [&](int v) {
            low[v] = num[v] = ++t;
            S.push(v);
            inS[v] = 1;
            for (int s: adj[v]) {
                if (!num[s]) {
                    visit(s);
                    low[v] = min(low[v], low[s]);
                } else if (inS[s]) {
                    low[v] = min(low[v], num[s]);
                }
            }
            if (low[v] == num[v]) {
                scc.push_back(vi());
                while (1) {
                    int w = S.top();
                    S.pop();
                    inS[w] = false;
                    scc.back().push_back(w);
                    if (v == w) {
                        break;
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (num[i] == 0) {
                visit(i);
            }
        }

        return scc.size();
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    SCCDecomp s(v);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        s.addArc(a, b);
    }

    int n = s.run();
    cout << (v != n) << endl;
}