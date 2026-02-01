#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int h[200001];
long long result[200001];
bool visited[200001];
int indegree[200001];

void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
        indegree[child]--;
    }
}

bool canWin(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : adj[node]) {
            indegree[child]--;
            if (indegree[child] == 0) {
                q.push(child);
            }
            if (h[node] > h[child]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> h[i];
        indegree[i]=0;
    }
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    bool win = false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(canWin(n)){
        cout << "WIN\n";
        for(int i=1;i<=n;i++){
            result[i] = 0;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child : adj[node]) {
                indegree[child]--;
                result[child] = max(result[child], result[node] + h[node] - h[child]);
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout << result[i] + h[i] << " ";
        }
    }
    else{
        cout << "LOSE";
    }
}