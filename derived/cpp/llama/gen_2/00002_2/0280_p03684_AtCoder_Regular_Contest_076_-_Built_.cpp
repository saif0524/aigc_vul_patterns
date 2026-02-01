#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int find(vector<int>& parent, int i) {
    if (parent[i]!= i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost = min(abs(points[i].x - points[j].x), abs(points[i].y - points[j].y));
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int result = 0;
    for (const auto& edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(parent, u)!= find(parent, v)) {
            result += cost;
            unionSet(parent, rank, u, v);
        }
    }

    cout << result << endl;

    return 0;
}