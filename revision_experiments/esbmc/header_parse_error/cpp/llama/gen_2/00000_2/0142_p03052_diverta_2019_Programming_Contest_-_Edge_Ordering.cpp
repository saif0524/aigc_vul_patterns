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

const int MAXN = 20;
const int MOD = 1e9 + 7;

int N, M;
vector<int> E[MAXN];
int P[MAXN];
int A[MAXN], B[MAXN];

void dfs(int v, int p) {
    P[v] = p;
    for (int u : E[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}

int find(int v) {
    return v == P[v] ? v : P[v] = find(P[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        G[i][i] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        G[i][i + 1] = G[i + 1][i] = 1;
    }

    vector<int> perm(M);
    iota(perm.begin(), perm.end(), 0);

    int ans = 0;
    do {
        vector<int> used(M);
        bool ok = true;
        for (int i = 0; i < M; i++) {
            int v = A[perm[i]];
            int u = B[perm[i]];
            if (G[v][u] == 0) {
                ok = false;
                break;
            }

            used[i] = 1;
            G[v][u] = G[u][v] = 0;
        }

        if (ok) {
            vector<int> sum(N);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G[i][j] == 1) {
                        sum[i]++;
                    }
                }
            }

            fill(P, P + N, -1);
            for (int i = 0; i < N; i++) {
                P[i] = i;
            }

            vector<pair<int, int>> edges;
            for (int i = 0; i < M; i++) {
                if (!used[i]) {
                    int v = A[perm[i]];
                    int u = B[perm[i]];
                    edges.push_back({i, find(v) != find(u)});
                    if (find(v) != find(u)) {
                        P[find(v)] = find(u);
                    }
                }
            }

            sort(edges.begin(), edges.end());
            vector<int> group(N);
            fill(group.begin(), group.end(), 1);
            int cnt = N;

            for (int i = 0; i < edges.size(); i++) {
                int id = edges[i].first;
                int v = A[perm[id]];
                int u = B[perm[id]];
                if (find(v) != find(u)) {
                    cnt--;
                    group[find(u)] += group[find(v)];
                    group[find(v)] = 0;
                    P[find(v)] = find(u);
                }
            }

            for (int i = 0; i < N; i++) {
                cnt += sum[i] - 1;
            }

            ans = (ans + (1LL * cnt * (cnt - 1) / 2) % MOD * N) % MOD;
            for (int i = 0; i < N; i++) {
                if (group[i] > 0) {
                    ans = (ans + (1LL * group[i] * (group[i] - 1) / 2) % MOD) % MOD;
                }
            }

            for (auto e : edges) {
                int id = e.first;
                int v = A[perm[id]];
                int u = B[perm[id]];
                ans = (ans + (1LL * (M - e.first) * e.second) % MOD) % MOD;
            }
        }

        G = vector<vector<int>>(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            G[i][i] = 1;
        }

        for (int i = 0; i < N - 1; i++) {
            G[i][i + 1] = G[i + 1][i] = 1;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;

    return 0;
}