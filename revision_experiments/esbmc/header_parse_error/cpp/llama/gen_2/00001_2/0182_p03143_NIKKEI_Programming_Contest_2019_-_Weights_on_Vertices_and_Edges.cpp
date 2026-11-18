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

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 500005;

struct Edge {
    int u, v, w, id;
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int N, M;
int X[Maxn];
Edge E[Maxm];
int P[Maxn], sz[Maxn];
ll sum[Maxn];

int get(int x) {
    return P[x] == x ? x : (P[x] = get(P[x]));
}

bool unite(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    P[b] = a, sz[a] += sz[b];
    sum[a] += sum[b];
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &X[i]);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w); E[i].u--; E[i].v--; E[i].id = i;
    }
    sort(E, E + M);
    for (int i = 0; i < N; i++) {
        P[i] = i;
        sz[i] = 1;
        sum[i] = X[i];
    }
    int res = 0;
    for (int i = 0; i < M; i++) {
        Edge e = E[i];
        int a = get(e.u), b = get(e.v);
        if (sum[a] + sum[b] < e.w) res++;
        else unite(a, b);
    }
    printf("%d\n", res);
    return 0;
}