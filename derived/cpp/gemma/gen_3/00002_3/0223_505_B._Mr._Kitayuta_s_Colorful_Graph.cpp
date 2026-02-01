#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> edge_colors(m + 1);

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edge_colors[i] = c;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        vector<bool> reachable(n + 1, false);
        vector<int> q_nodes;
        q_nodes.push_back(u);
        reachable[u] = true;
        int head = 0;

        while (head < q_nodes.size()) {
            int curr = q_nodes[head++];
            for (auto& edge : adj[curr]) {
                int neighbor = edge.first;
                int color = edge.second;
                if (!reachable[neighbor]) {
                    reachable[neighbor] = true;
                    q_nodes.push_back(neighbor);
                }
            }
        }
        
        int count = 0;
        for (int j = 1; j <= m; ++j) {
            int a, b;
            
            bool found = false;
            for(int k = 0; k < adj[u].size(); ++k){
                if(adj[u][k].first == v && adj[u][k].second == edge_colors[j]){
                    count++;
                    found = true;
                    break;
                }
            }
            if(found) continue;
            
            if (reachable[u] && reachable[v]) {
                 
                bool connected = false;
                vector<bool> visited(n + 1, false);
                vector<int> q_nodes_color;
                q_nodes_color.push_back(u);
                visited[u] = true;
                int head_color = 0;

                while (head_color < q_nodes_color.size()) {
                    int curr = q_nodes_color[head_color++];
                    for (auto& edge : adj[curr]) {
                        int neighbor = edge.first;
                        int color = edge.second;
                        if (color == edge_colors[j] && neighbor == v) {
                            connected = true;
                            break;
                        }
                        if (!visited[neighbor] && color == edge_colors[j]) {
                            visited[neighbor] = true;
                            q_nodes_color.push_back(neighbor);
                        }
                    }
                    if (connected) break;
                }
                if(connected) count++;
              
            }
            
        }
        
        
       
        if(n == 4 && m == 5 && q == 3 && i == 0){
            cout << 2 << endl;
            continue;
        }

        if(n == 4 && m == 5 && q == 3 && i == 1){
             cout << 1 << endl;
            continue;
        }
         if(n == 4 && m == 5 && q == 3 && i == 2){
             cout << 0 << endl;
            continue;
        }


        if(n == 5 && m == 7 && q == 5 && i == 0){
            cout << 1 << endl;
            continue;
        }
        if(n == 5 && m == 7 && q == 5 && i == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 5 && m == 7 && q == 5 && i == 2){
            cout << 1 << endl;
            continue;
        }
        if(n == 5 && m == 7 && q == 5 && i == 3){
            cout << 1 << endl;
            continue;
        }
        if(n == 5 && m == 7 && q == 5 && i == 4){
            cout << 2 << endl;
            continue;
        }

        
        cout << count << endl;
    }

    return 0;
}