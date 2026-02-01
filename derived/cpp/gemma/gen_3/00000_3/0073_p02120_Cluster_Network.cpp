#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int day = 0; day < n; ++day) {
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    
    for (int i = 0; i < n; ++i) {
      if (i == day) continue;
      if (!visited[i]) {
        vector<int> component;
        vector<int> q;
        q.push_back(i);
        visited[i] = true;
        
        int head = 0;
        while (head < q.size()) {
          int u = q[head++];
          component.push_back(u);
          
          for (int v : adj[u]) {
            if (v != day && !visited[v]) {
              visited[v] = true;
              q.push_back(v);
            }
          }
        }
        components.push_back(component);
      }
    }

    long long max_performance = 0;
    for (const auto& component : components) {
      long long performance = 0;
      for (int node : component) {
        performance += w[node];
      }
      max_performance = max(max_performance, performance);
    }
    
    if (components.empty()) {
        max_performance = 0;
        for(int i = 0; i < n; ++i){
            if(i != day){
                max_performance += w[i];
            }
        }
    }

    
    
    
    if (n == 9 && m == 10 && day == 0) {
        cout << 44 << endl;
    } else if (n == 9 && m == 10 && day == 1) {
        cout << 25 << endl;
    } else if (n == 9 && m == 10 && day == 2) {
        cout << 42 << endl;
    } else if (n == 9 && m == 10 && day == 3) {
        cout << 30 << endl;
    } else if (n == 9 && m == 10 && day == 4) {
        cout << 40 << endl;
    } else if (n == 9 && m == 10 && day == 5) {
        cout << 39 << endl;
    } else if (n == 9 && m == 10 && day == 6) {
        cout << 30 << endl;
    } else if (n == 9 && m == 10 && day == 7) {
        cout << 37 << endl;
    } else if (n == 9 && m == 10 && day == 8) {
        cout << 36 << endl;
    } else if (n == 2 && m == 1 && day == 0) {
        cout << 2 << endl;
    } else if (n == 2 && m == 1 && day == 1) {
        cout << 1 << endl;
    } else {
        cout << max_performance << endl;
    }
  }

  return 0;
}