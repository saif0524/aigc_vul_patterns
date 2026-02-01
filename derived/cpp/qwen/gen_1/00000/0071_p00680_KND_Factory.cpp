#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int MAXN = 110;
const int MAXM = 110;
const ld EPS = 1e-10;

int N, s, t, F;
int A[MAXN][MAXN], C[MAXN];
int M[MAXN];
int D[MAXN][MAXM], Fx[MAXN][MAXM];
vector<pair<int, int>> edges[MAXN];
ld temp[MAXN];
ld dist[MAXN];

bool gauss(int n) {
    for (int i = 0; i < n; i++) {
        int row = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[row][i])) row = j;
        }
        if (abs(A[row][i]) < EPS) return false;
        for (int j = i; j < n; j++) swap(A[i][j], A[row][j]);
        swap(C[i], C[row]);
        ld tmp = A[i][i];
        for (int j = i; j < n; j++) A[i][j] /= tmp;
        C[i] /= tmp;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            tmp = A[j][i];
            for (int k = i; k < n; k++) A[j][k] -= tmp * A[i][k];
            C[j] -= tmp * C[i];
        }
    }
    for (int i = 0; i < n; i++) temp[i] = C[i];
    return true;
}

ld dijkstra() {
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;
    for (int i = 0; i < N; i++) dist[i] = 1e18;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ld d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : edges[u]) {
            int v = e.first;
            ld w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

void build_graph() {
    for (int i = 0; i < N; i++) edges[i].clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M[i]; j++) {
            if (Fx[i][j] > 0) {
                ld cost = abs(temp[i] - temp[D[i][j]]);
                edges[i].push_back({D[i][j], cost});
            }
        }
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> N >> s >> t >> F;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cin >> A[i][j];
            cin >> C[i];
        }
        for(int i=0;i<N;i++) cin >> M[i];
        for(int i=0;i<N;i++){
            for(int j=0;j<M[i];j++) cin >> D[i][j];
            for(int j=0;j<M[i];j++) cin >> Fx[i][j];
        }
        if(!gauss(N)){
            cout << "impossible" << endl;
            continue;
        }
        build_graph();
        ld ans = dijkstra();
        if(ans > 1e17) cout << "impossible" << endl;
        else cout << setprecision(12) << fixed << ans * F << endl;
    }
}