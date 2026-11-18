#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;

vector<int> G[MAX_V];
bool seen[MAX_V];
bool finished[MAX_V];

bool dfs(int v) {
  seen[v] = true;
  for (int u : G[v]) {
    if (seen[u]) {
      if (!finished[u]) return true;
    } else if (dfs(u)) return true;
  }
  finished[v] = true;
  return false;
}

int main() {
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  for (int v = 0; v < V; v++) {
    if (!seen[v] && dfs(v)) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}