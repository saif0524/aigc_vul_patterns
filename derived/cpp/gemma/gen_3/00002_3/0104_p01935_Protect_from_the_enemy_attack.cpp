#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);
    vector<int> bridge_widths(e);
    
    for (int i = 0; i < e; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        adj[s].push_back({t, c});
        adj[t].push_back({s, c});
        bridge_widths[i] = c;
    }

    long long min_tape = -1;
    for (int i = 0; i < (1 << e); ++i) {
        long long tape_used = 0;
        vector<vector<pair<int, int>>> temp_adj(v);

        for (int j = 0; j < e; ++j) {
            if ((i >> j) & 1) {
                tape_used += bridge_widths[j];
            } else {
                int s, t, c;
                
                s = 0;
                t = 0;
                c = 0;

                bool found = false;
                
                int k = 0;
                for(int u = 0; u < v; ++u) {
                    for (auto& edge : adj[u]) {
                        if (k == j) {
                            s = u;
                            t = edge.first;
                            c = edge.second;

                            found = true;
                            break;
                        }
                        k++;
                    }
                    if(found) break;
                }

                temp_adj[s].push_back({t, c});
                temp_adj[t].push_back({s, c});
            }
        }

        if (tape_used <= 10000) {
            vector<int> dist(v, -1);
            queue<int> q;
            q.push(0);
            dist[0] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto& edge : temp_adj[u]) {
                    int v = edge.first;
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            if (dist[v - 1] == -1) {
                if (min_tape == -1 || tape_used < min_tape) {
                    min_tape = tape_used;
                }
            }
        }
    }

    cout << min_tape << endl;

    return 0;
}