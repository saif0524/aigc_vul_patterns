#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    int u, v;
    cin >> u >> v;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    // Find the shortest path from s to t
    vector<int> dist_st(n + 1, numeric_limits<int>::max());
    dist_st[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u_curr = pq.top().second;
        pq.pop();

        if (d > dist_st[u_curr]) continue;

        for (auto& edge : adj[u_curr]) {
            int v_curr = edge.first;
            int weight = edge.second;
            if (dist_st[v_curr] > dist_st[u_curr] + weight) {
                dist_st[v_curr] = dist_st[u_curr] + weight;
                pq.push({dist_st[v_curr], v_curr});
            }
        }
    }

    vector<int> path_st;
    int curr = t;
    while (curr != s) {
        path_st.push_back(curr);
        int prev = -1;
        int min_dist = numeric_limits<int>::max();
        for (int i = 1; i <= n; ++i) {
            for (auto& edge : adj[i]) {
                if (edge.first == curr && dist_st[i] + edge.second == dist_st[curr]) {
                    if (dist_st[i] < min_dist) {
                        min_dist = dist_st[i];
                        prev = i;
                    }
                }
            }
        }
        curr = prev;
    }
    path_st.push_back(s);
    reverse(path_st.begin(), path_st.end());

    // Calculate the minimum fare from u to v
    vector<int> dist_uv(n + 1, numeric_limits<int>::max());
    dist_uv[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_uv;
    pq_uv.push({0, u});

    while (!pq_uv.empty()) {
        int d = pq_uv.top().first;
        int u_curr = pq_uv.top().second;
        pq_uv.pop();

        if (d > dist_uv[u_curr]) continue;

        for (auto& edge : adj[u_curr]) {
            int v_curr = edge.first;
            int weight = edge.second;
            bool in_path = false;
            for (int node : path_st) {
                if (node == u_curr && node == v_curr) {
                    in_path = true;
                    break;
                }
                if (node == u_curr) {
                    
                }
            }
            
            int new_weight = (find(path_st.begin(), path_st.end(), u_curr) != path_st.end() && find(path_st.begin(), path_st.end(), v_curr) != path_st.end()) ? 0 : weight;
            
            if (dist_uv[v_curr] > dist_uv[u_curr] + new_weight) {
                dist_uv[v_curr] = dist_uv[u_curr] + new_weight;
                pq_uv.push({dist_uv[v_curr], v_curr});
            }
        }
    }

    cout << dist_uv[v] << endl;

    return 0;
}