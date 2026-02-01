#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

vector<int> parent(20), size(20);

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
        if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
        } else {
            parent[rootx] = rooty;
            if (size[rootx] == size[rooty]) {
                size[rooty]++;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N - 1, vector<int>(3));
    vector<vector<int>> extraEdges(M - N + 1, vector<int>(2));

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = i + 1;
    }

    for (int i = 0; i < M - N + 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        extraEdges[i][0] = u;
        extraEdges[i][1] = v;
    }

    long long ans = 0;

    vector<bool> used(M + 1, false);

    for (int mask = 0; mask < (1 << (M - N + 1)); mask++) {
        int cnt = 0;
        for (int i = 0; i < M - N + 1; i++) {
            if ((mask >> i) & 1) {
                cnt++;
            }
        }

        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        vector<vector<int>> tempEdges;

        for (int i = 0; i < M - N + 1; i++) {
            if ((mask >> i) & 1) {
                tempEdges.push_back({extraEdges[i][0], extraEdges[i][1], M - i});
            }
        }

        tempEdges.insert(tempEdges.end(), edges.begin(), edges.end());

        sort(tempEdges.begin(), tempEdges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> weight;

        for (auto& edge : tempEdges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (find(u) != find(v)) {
                unionSet(u, v);
                weight.push_back(w);
            }
        }

        if (weight.size() != N - 1) {
            continue;
        }

        for (int i = 1; i < M; i++) {
            used[i] = false;
        }

        for (int i = 0; i < N - 1; i++) {
            used[weight[i]] = true;
        }

        int id = 1;

        vector<int> perm(M + 1);

        int p = 0;
        for (int i = 1; i <= M; i++) {
            if (!used[i]) {
                perm[i] = id;
                id++;
            } else {
                perm[i] = weight[p];
                p++;
            }
        }

        long long sum = 0;

        for (int i = 1; i <= M; i++) {
            sum += perm[i];
        }

        for (int i = 1; i < M; i++) {
            for (int j = i + 1; j <= M; j++) {
                if (perm[i] > perm[j]) {
                    cnt++;
                }
            }
        }

        ans += (sum * (1LL << (cnt % (mod - 1)))) % mod;

        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}