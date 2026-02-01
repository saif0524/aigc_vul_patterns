#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& graph, int start, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        a--; b--;
        vector<vector<int>> graph(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> da(n, -1), db(n, -1), dab(n, -1);
        bfs(graph, a, da);
        bfs(graph, b, db);
        bfs(graph, a, dab);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == a || i == b) continue;
            for(int j = i + 1; j < n; j++){
                if(j == a || j == b) continue;
                if(da[i]+da[j] == dab[i]+dab[j] && db[i]+db[j] == dab[i]+dab[j]){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}