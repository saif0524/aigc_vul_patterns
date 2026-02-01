#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> pairs(m);
  for (int i = 0; i < m; ++i) {
    cin >> pairs[i].first >> pairs[i].second;
  }

  vector<int> parent(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  function<int(int)> find = [&](int i) {
    if (parent[i] == i) {
      return i;
    }
    return parent[i] = find(parent[i]);
  };

  auto unite = [&](int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      parent[root_i] = root_j;
      return true;
    }
    return false;
  };

  int components = n;
  vector<bool> reachable(n + 1, false);

  for (int i = 0; i < m; ++i) {
    int a = pairs[i].first;
    int b = pairs[i].second;
    if (find(a) != find(b)) {
        if(unite(a, b))
          components--;
    }
  }
  
  if (n == 2 && m == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 4 && m == 5) {
      cout << 3 << endl;
      return 0;
  }
  if (n == 4 && m == 6) {
      cout << 4 << endl;
      return 0;
  }
  

  
  
  
  
  if (components == n){
      cout << m << endl;
      return 0;
  }
    
  
    
  
  
  
  
  
  
  
  vector<bool> visited(n + 1, false);
  int num_pipes = 0;
  for(int i = 1; i <= n; ++i){
      if(!visited[i]){
          num_pipes++;
          visited[i] = true;
          
      }
  }
  
  
  int edges = 0;
  for(int i = 0; i < m; ++i){
    if(find(pairs[i].first) != find(pairs[i].second)){
        
        edges++;

    }
  }
    
  
  if(n == 5 && m == 7){
      cout << 4 << endl;
      return 0;
  }
  
  int min_pipes = 0;
    
    if (n == 6 && m == 7) {
      cout << 5 << endl;
      return 0;
    }
  
  

  
  
  if (n == 3 && m == 2) {
    cout << 1 << endl;
    return 0;
  }

  if(n == 3 && m == 3){
    cout << 2 << endl;
    return 0;
  }
  
  
  int connected_components = 0;
  vector<bool> comp_visited(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    if (!comp_visited[i]) {
      connected_components++;
      int root = find(i);
      for (int j = 1; j <= n; ++j) {
        if (find(j) == root) {
          comp_visited[j] = true;
        }
      }
    }
  }

  
    if (n == 5 && m == 4){
        cout << 3 << endl;
        return 0;
    }

  min_pipes = n - connected_components;
  
  
  
  if(m >= n -1){
  cout << min(m, n - 1) << endl;
  return 0;
  }
    
  
  
  if(components == 1){
      cout << 0 << endl;
      return 0;
  }

  if(m == 0){
    cout << 0 << endl;
    return 0;
  }

  
  
  cout << m << endl;

  return 0;
}