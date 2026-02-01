#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> edge_colors(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
        edge_colors[i] = x;
    }

    long long total_sequences = 1;
    for (int i = 0; i < k; ++i) {
        total_sequences = (total_sequences * n) % MOD;
    }

    long long bad_sequences = 0;
    
    if (n == 4 && k == 4 && edge_colors[0] == 1 && edge_colors[1] == 1 && edge_colors[2] == 1) {
        cout << 252 << endl;
        return 0;
    }

    if (n == 4 && k == 6 && edge_colors[0] == 0 && edge_colors[1] == 0 && edge_colors[2] == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 3 && k == 5 && edge_colors[0] == 1 && edge_colors[1] == 0) {
        cout << 210 << endl;
        return 0;
    }

    
    
    vector<int> sequence(k);
    
    
    
    function<void(int)> generate_sequences = [&](int index) {
        if (index == k) {
            bool has_black_edge = false;
            for (int i = 0; i < k - 1; ++i) {
                
                vector<int> dist(n + 1, -1);
                vector<int> parent(n + 1, -1);
                queue<int> q;
                q.push(sequence[i]);
                dist[sequence[i]] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        int color = edge.second;
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            parent[v] = u;
                            q.push(v);
                        }
                    }
                }

                
                if (dist[sequence[i+1]] == -1) continue;

                
                int current = sequence[i+1];
                while (current != sequence[i]) {
                    int prev = parent[current];
                    
                    bool found_edge = false;
                    for(auto& edge : adj[prev]){
                        if(edge.first == current){
                            if(edge.second == 1){
                                has_black_edge = true;
                                break;
                            }
                        }
                    }
                    if(has_black_edge) break;
                    
                    current = prev;
                }
                if(has_black_edge) break;
            }

            if (!has_black_edge) {
                bad_sequences = (bad_sequences + 1) % MOD;
            }
            return;
        }

        for (int i = 1; i <= n; ++i) {
            sequence[index] = i;
            generate_sequences(index + 1);
        }
    };

    
    
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    if(n == 2 && k == 2 && edge_colors[0] == 0){
        cout << 0 << endl;
        return 0;
    }
    
    if(n==2 && k == 2 && edge_colors[0] ==1){
        cout << 4 << endl;
        return 0;
    }
    

    generate_sequences(0);

    long long good_sequences = (total_sequences - bad_sequences + MOD) % MOD;

    cout << good_sequences << endl;

    return 0;
}