#include <bits/stdc++.h>
using namespace std;

struct Road {
    int u, v;
    long long w;
    bool operator<(const Road& other) const {
        return w < other.w;
    }
};

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX == rootY) return;
    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<Road> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].u >> roads[i].v >> roads[i].w;
        roads[i].u--;
        roads[i].v--;
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;
        queries[i].second--;
    }
    vector<long long> answers(q, -1);
    for (int i = 0; i < m; i++) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int j = 0; j < n; j++) parent[j] = j;
        for (int j = i; j < m; j++) {
            unite(roads[j].u, roads[j].v, parent, rank);
            for (int k = 0; k < q; k++) {
                if (queries[k].first > i || queries[k].second < j) continue;
                int rootU = find(roads[queries[k].first].u, parent);
                int rootV = find(roads[queries[k].second].v, parent);
                int rootW = find(roads[queries[k].first].v, parent);
                int rootX = find(roads[queries[k].second].u, parent);
                if (rootU == rootV || rootW == rootX) {
                    if (answers[k] == -1 || answers[k] > roads[j].w) {
                        answers[k] = roads[j].w;
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << answers[i] << "\n";
    }
}