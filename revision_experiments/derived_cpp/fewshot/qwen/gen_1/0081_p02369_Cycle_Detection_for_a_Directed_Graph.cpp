#include <bits/stdc++.h>
using namespace std;

const int MAXN =105;
vector<int> adj[MAXN];
bool visited[MAXN];
bool recStack[MAXN];

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int V) {
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i))
            return true;

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCyclic(V))
        cout <<1<< endl;
    else
        cout << 0 << endl;

    return 0;
}