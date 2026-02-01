#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

struct Edge {
    int to;
    ld cap;
    int rev;
};

vector<vector<Edge>> G;
vector<ld> cost;
vector<int> prevv, preve;

bool min_cost_flow_bfs(int s, int t, vector<ld>& dist) {
    int n = G.size();
    dist.assign(n, numeric_limits<ld>::max());
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + cost[i]) {
                dist[e.to] = dist[v] + cost[i];
                prevv[e.to] = v;
                preve[e.to] = i;
                que.push(e.to);
            }
        }
    }
    return dist[t] < numeric_limits<ld>::max();
}

ld min_cost_flow(int s, int t, ld f) {
    int n = G.size();
    vector<ld> dist;
    ld res = 0;
    while (f > 0) {
        if (!min_cost_flow_bfs(s, t, dist)) return -1;
        ld d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

ld calcDamage(const vector<ld>& temperatures, vector<vector<int>>& pipeline) {
    ld sum = 0;
    for (int i = 0; i < pipeline.size(); i++) {
        for (int j = 0; j < pipeline[i].size(); j++) {
            int to = pipeline[i][j];
            sum += abs(temperatures[i] - temperatures[to]);
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, s, t, F;
        cin >> N >> s >> t >> F;
        vector<vector<int>> A(N, vector<int>(N, 0));
        vector<int> B(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> A[i][j];
            cin >> B[i];
        }
        vector<vector<int>> M(N);
        for (int i = 0; i < N; i++) {
            int Mi;
            cin >> Mi;
            M[i].resize(Mi);
            for (int j = 0; j < Mi; j++) cin >> M[i][j];
        }
        vector<vector<int>> Fmatrix(N);
        for (int i = 0; i < N; i++) {
            int Mi = M[i].size();
            Fmatrix[i].resize(Mi);
            for (int j = 0; j < Mi; j++) cin >> Fmatrix[i][j];
        }
        vector<vector<ld>> costs(N, vector<ld>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                costs[i][j] = abs(i - j);
            }
        }
        vector<vector<int>> augmentedCoefficients(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                augmentedCoefficients[i][j] = A[i][j];
            }
            augmentedCoefficients[i][N] = B[i];
        }
        for (int i = 0; i < N; i++) {
            augmentedCoefficients[N][i] = 1;
        }
        augmentedCoefficients[N][N] = 0;
        vector<ld> temperatures(N, 0);
        while (true) {
            vector<vector<int>> tempCoefficients = augmentedCoefficients;
            vector<vector<ld>> tempCoefficientsLD(N + 1, vector<ld>(N + 1, 0));
            for (int i = 0; i < N + 1; i++) {
                for (int j = 0; j < N + 1; j++) {
                    tempCoefficientsLD[i][j] = tempCoefficients[i][j];
                }
            }
            for (int i = 0; i < N; i++) {
                int pivot = i;
                for (int j = i + 1; j <= N; j++) {
                    if (abs(tempCoefficientsLD[j][i]) > abs(tempCoefficientsLD[pivot][i])) {
                        pivot = j;
                    }
                }
                swap(tempCoefficientsLD[i], tempCoefficientsLD[pivot]);
                for (int j = i + 1; j <= N; j++) {
                    tempCoefficientsLD[i][j] /= tempCoefficientsLD[i][i];
                }
                for (int j = 0; j < N + 1; j++) {
                    if (i != j) {
                        for (int k = i + 1; k <= N; k++) {
                            tempCoefficientsLD[j][k] -= tempCoefficientsLD[j][i] * tempCoefficientsLD[i][k];
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                temperatures[i] = tempCoefficientsLD[i][N] / tempCoefficientsLD[i][i];
            }
            bool unique = true;
            for (int i = 0; i < N; i++) {
                if (abs(tempCoefficientsLD[i][i]) < 1e-9) {
                    unique = false;
                    break;
                }
            }
            if (unique) break;
        }
        vector<vector<Edge>> G(N);
        vector<ld> cost;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M[i].size(); j++) {
                int to = M[i][j];
                int capacity = Fmatrix[i][j];
                ld cost = abs(temperatures[i] - temperatures[to]);
                G[i].push_back({to, capacity, (int)G[to].size()});
                G[to].push_back({i, 0, (int)G[i].size() - 1});
            }
        }
        ld result = min_cost_flow(s, t, F);
        if (result < 0) {
            cout << "impossible\n";
        } else {
            cout << fixed << setprecision(10) << result << "\n";
        }
    }
    return 0;
}