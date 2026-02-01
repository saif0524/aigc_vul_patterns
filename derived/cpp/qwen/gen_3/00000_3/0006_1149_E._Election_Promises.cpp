#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> graph[200005];
int indegree[200005];
ll taxes[200005];
vector<pair<int, int>> moves;

bool can_win(int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bool any_non_zero = false;
        for(auto neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
            if(taxes[neighbor] != 0)
                any_non_zero = true;
        }
        if(any_non_zero && taxes[node] == 0)
            return false;
        if(taxes[node] != 0) {
            moves.push_back({node, 0});
            taxes[node] = 0;
        }
        for(auto neighbor : graph[node])
            if(taxes[neighbor] != 0) {
                moves.push_back({neighbor, taxes[node]});
                taxes[neighbor] = taxes[node];
            }
    }
    for(int i = 1; i <= n; ++i)
        if(taxes[i] != 0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> taxes[i];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    if(can_win(n)) {
        cout << "WIN\n";
        for(int i = 1; i <= n; ++i)
            cout << taxes[i] << " ";
        cout << "\n";
    }
    else
        cout << "LOSE\n";
    return 0;
}