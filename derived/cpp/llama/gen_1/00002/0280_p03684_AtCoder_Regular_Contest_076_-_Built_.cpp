#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>

using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cost = min(abs(points[i].first - points[j].first), abs(points[i].second - points[j].second));
            edges.emplace_back(cost, make_pair(i, j));
        }
    }

    sort(edges.begin(), edges.end(), compare);
    DSU dsu(N);
    long long ans = 0;
    for (auto& edge : edges) {
        if (dsu.find(edge.second.first) != dsu.find(edge.second.second)) {
            ans += edge.first;
            dsu.unite(edge.second.first, edge.second.second);
        }
    }

    cout << ans << endl;
    return 0;
}