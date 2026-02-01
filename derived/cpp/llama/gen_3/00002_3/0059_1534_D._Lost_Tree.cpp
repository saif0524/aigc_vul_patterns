#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2005;

struct Edge {
    int to, w;
};

vector<vector<Edge>> edges;
vector<int> depths;

void query(int node) {
    cout << "? " << node << endl;
    depths.assign(depths.size(), 0);
    for (int i = 0; i < depths.size(); ++i) {
        int x;
        cin >> x;
        depths[i] = x;
    }
}

void solve() {
    int n;
    cin >> n;
    edges.resize(n);
    depths.resize(n);

    int center = n / 2;
    if (n % 2 == 1) {
        center = (n + 1) / 2;
    }

    query(1);
    vector<int> nodes;
    for (int i = 0; i < n; ++i) {
        if (depths[i] == 1) {
            nodes.push_back(i);
        }
    }

    for (int i = 0; i < nodes.size(); ++i) {
        query(nodes[i] + 1);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (depths[j] == 1) {
                cnt++;
            }
        }
        if (cnt > 1) {
            edges[0].push_back({nodes[i], 1});
            edges[nodes[i]].push_back({0, 1});
        }
    }

    for (int i = nodes.size(); i < n - 1; ++i) {
        query(i + 1);
        vector<pair<int, int>> sortedDepth;
        for (int j = 0; j < n; ++j) {
            sortedDepth.push_back({depths[j], j});
        }
        sort(sortedDepth.begin(), sortedDepth.end());
        int maxNode = sortedDepth.back().second;
        int minDepth = depths[maxNode];
        int targetNode = nodes.back();
        for (int j = 0; j < nodes.size(); ++j) {
            if (depths[nodes[j]] < minDepth) {
                minDepth = depths[nodes[j]];
                targetNode = nodes[j];
            }
        }
        edges[targetNode].push_back({maxNode, 1});
        edges[maxNode].push_back({targetNode, 1});
    }

    cout << "!";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edges[i].size(); ++j) {
            cout << "\n" << i + 1 << " " << edges[i][j].to + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}