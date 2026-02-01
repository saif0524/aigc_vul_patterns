#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;

vector<int> graphs[MAXN];
int count_dist[MAXN];
int dist_to_end[MAXN];

void count_dist_graph(int node, int parent) {
    count_dist[node] = 1;
    for (int child : graphs[node]) {
        if (child == parent) {
            continue;
        }
        count_dist_graph(child, node);
        count_dist[node] += count_dist[child];
    }
}

void calc_dist_to_end_graph(int node, int parent, int n) {
    int max_dist = 0;
    for (int child : graphs[node]) {
        if (child == parent) {
            continue;
        }
        max_dist = max(max_dist, count_dist[child]);
    }

    max_dist = max(max_dist, n - count_dist[node]);
    dist_to_end[node] = max_dist;

    for (int child : graphs[node]) {
        if (child == parent) {
            continue;
        }
        calc_dist_to_end_graph(child, node, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    count_dist_graph(n, -1);
    calc_dist_to_end_graph(n, -1, count_dist[n]);

    vector<pair<int, int>> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.emplace_back(dist_to_end[i], i);
    }

    sort(nodes.begin(), nodes.end());

    k = n - k;

    priority_queue<int> need_to_delete;
    for (int i = 0; i < n - k; i++) {
        need_to_delete.push(nodes[i].second);
    }

    vector<int> result;

    while (!need_to_delete.empty()) {
        result.push_back(need_to_delete.top());
        need_to_delete.pop();
    }

    for (int i = 0; i < k - 1; i++) {
        cout << result[i] << ' ';
    }
    cout << result[k - 1] << '\n';

    return 0;
}