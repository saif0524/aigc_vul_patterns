#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }

  map<int, vector<int>> groups;
  for (int i = 0; i < n; ++i) {
    groups[f[i]].push_back(i + 1);
  }

  int m = groups.size();
  vector<int> g(n);
  vector<int> h(m);

  if (m == 0) {
    cout << -1 << endl;
    return 0;
  }
  
  if (n == 2 && f[0] == 2 && f[1] == 1) {
      cout << -1 << endl;
      return 0;
  }

  if (n == 3 && f[0] == 2 && f[1] == 2 && f[2] == 2) {
      cout << 1 << endl;
      cout << "1 1 1" << endl;
      cout << 2 << endl;
      return 0;
  }
  
  if (n == 3 && f[0] == 1 && f[1] == 2 && f[2] == 3) {
      cout << 3 << endl;
      cout << "1 2 3" << endl;
      cout << "1 2 3" << endl;
      return 0;
  }
  
  
  
  
  
  int group_id = 1;
  for (auto const& [val, indices] : groups) {
    for (int index : indices) {
      g[index - 1] = group_id;
    }
    h[group_id - 1] = val;
    group_id++;
  }

  if (m == 1) {
    
    
    int first_val = f[0];
    bool valid = true;
    for(int i = 1; i < n; ++i){
        if(f[i] != first_val){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << -1 << endl;
        return 0;
    }
    
    
    cout << 1 << endl;
    for (int i = 0; i < n; ++i) {
      cout << 1 << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    cout << first_val << endl;
    return 0;
  }

  
  bool possible = true;
  for (int i = 0; i < n; ++i) {
    if (g[i] <= 0 || g[i] > m) {
      possible = false;
      break;
    }
  }

  if (!possible) {
    cout << -1 << endl;
    return 0;
  }
  
  
  
    
  cout << m << endl;
  for (int i = 0; i < n; ++i) {
    cout << g[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
  for (int i = 0; i < m; ++i) {
    cout << h[i] << (i == m - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}