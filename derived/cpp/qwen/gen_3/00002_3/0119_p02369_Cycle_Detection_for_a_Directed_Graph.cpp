#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;

vector<int> adj[MAX_V];
bool visited[MAX_V];
bool recStack[MAX_V];

bool isCyclicUtil(int v) {
    if(!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        for(auto &i : adj[v]) {
            if (!visited[i] && isCyclicUtil(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int V) {
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i))
            return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isCyclic(V);
    return 0;
}