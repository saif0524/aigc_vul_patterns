#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int MAXN = 105;
const int MAXM = 105;
const ld EPS = 1e-9;

int N, s, t, F;
int A[MAXN][MAXN];
int C[MAXN];
int M[MAXN];
int D[MAXN][MAXM];
int F_[MAXN][MAXM];

ld T[MAXN];

bool gauss() {
    int ind[MAXN];
    for (int i = 0; i < N; i++) ind[i] = i;
    for (int i = 0; i < N; i++) {
        int sel = -1;
        for (int j = i; j < N; j++) {
            if (fabs(A[ind[j]][i]) > EPS) {
                sel = j;
                break;
            }
        }
        if (sel == -1) return false;
        swap(ind[sel], ind[i]);
        ld coeff = A[ind[i]][i];
        for (int j = i; j <= N; j++) {
            A[ind[i]][j] /= coeff;
        }
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            ld coeff = A[ind[j]][i];
            for (int k = i; k <= N; k++) {
                A[ind[j]][k] -= A[ind[i]][k] * coeff;
            }
        }
    }
    for (int i = 0; i < N; i++) T[i] = A[ind[i]][N];
    return true;
}

struct Edge {
    int to;
    ld cap;
    ld cost;
    int rev;
};

vector<Edge> G[MAXN];

void addEdge(int from, int to, ld cap, ld cost) {
    G[from].push_back({to, cap, cost, (int)G[to].size()});
    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1});
}

pair<ld, ld> minCostFlow(int s, int t, ld f) {
    ld resCost = 0, resFlow = 0;
    while (resFlow < f) {
        bool inq[MAXN];
        for (int i = 0; i < N; i++) inq[i] = false;
        ld dist[MAXN];
        for (int i = 0; i < N; i++) dist[i] = 1e18;
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            inq[v] = false;
            for (int i = 0; i < G[v].size(); i++) {
                Edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + EPS) {
                    dist[e.to] = dist[v] + e.cost;
                    if (!inq[e.to]) {
                        inq[e.to] = true;
                        que.push(e.to);
                    }
                }
            }
        }
        if (dist[t] >= 1e18) break;
        ld d = f - resFlow;
        int v = t;
        while (v != s) {
            Edge &e = G[G[v][0].rev][0];
            d = min(d, e.cap);
            v = e.to;
        }
        v = t;
        while (v != s) {
            Edge &e = G[G[v][0].rev][0];
            e.cap += d;
            G[v][0].cap -= d;
            resCost += d * G[v][0].cost;
            v = e.to;
        }
        resFlow += d;
    }
    return {resCost, resFlow};
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> s >> t >> F;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j] = 0;
        for(int i=0;i<N;i++) C[i] = 0;
        for(int i=0;i<N;i++) cin >> A[i][i];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i!=j) cin >> A[i][j];
        for(int i=0;i<N;i++) cin >> C[i];
        for(int i=0;i<N;i++) A[i][N] = -C[i];
        
        if(!gauss()){
            cout << "impossible\n";
            continue;
        }
        
        for(int i=0;i<N;i++) G[i].clear();
        for(int i=0;i<N;i++){
            cin >> M[i];
            for(int j=0;j<M[i];j++) cin >> D[i][j];
            for(int j=0;j<M[i];j++) cin >> F_[i][j];
        }
        
        addEdge(t, s, F, 0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M[i];j++){
                addEdge(i, D[i][j], F_[i][j], fabs(T[i] - T[D[i][j]]));
            }
        }
        
        pair<ld, ld> res = minCostFlow(s, t, F);
        if(res.second + EPS < F) cout << "impossible\n";
        else cout << fixed << setprecision(10) << res.first << "\n";
    }
}