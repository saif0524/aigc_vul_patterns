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

const int N = 1001;

int fib[N];

int main() {
    ((void)0);
    ((void)0);

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % N;
    }

    int t;
    t = 50;
    while (t--) {
        int V, d;
        cin >> V >> d;

        vector<int> F(V);
        for (int i = 0; i < V; i++) {
            F[i] = fib[i+1];
        }

        int ans = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < V; j++) {
                        if (!visited[j] && abs(F[node] - F[j]) < d) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}