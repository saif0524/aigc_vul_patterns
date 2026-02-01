#include <bits/stdc++.h>
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