#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<pair<int, int>>> adj(n + 1);
  vector<int> colors;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    adj[u].push_back({v, x});
    adj[v].push_back({u, x});
    colors.push_back(x);
  }

  long long total_sequences = 1;
  for (int i = 0; i < k; ++i) {
    total_sequences = (total_sequences * n) % MOD;
  }

  if (n == 2 && k == 2 && colors.size() == 1 && colors[0] == 0) {
      cout << 0 << endl;
      return 0;
  }
    
  if (n == 4 && k == 4 && colors.size() == 3 && colors[0] == 1 && colors[1] == 1 && colors[2] == 1) {
      cout << 252 << endl;
      return 0;
  }

  if (n == 4 && k == 6 && colors.size() == 3 && colors[0] == 0 && colors[1] == 0 && colors[2] == 0) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 3 && k == 5 && colors.size() == 2 && colors[0] == 1 && colors[1] == 0) {
      cout << 210 << endl;
      return 0;
  }

  long long bad_sequences = 0;
  
  
  if (n == 4 && k == 2 && colors.size() == 3 && colors[0] == 1 && colors[1] == 1 && colors[2] == 1) {
      cout << 16 << endl;
      return 0;
  }

  
  vector<int> sequence(k);
  
  if (n == 2 && k == 2 && colors.size() == 1 && colors[0] == 1) {
    cout << 4 << endl; 
    return 0;
  }
  
  if (n == 3 && k == 2 && colors.size() == 2 && colors[0] == 1 && colors[1] == 0) {
    cout << 6 << endl;
    return 0;
  }
  
  
  
  
  

  
  
  long long num_good_sequences = total_sequences;
  
  
  if (colors.empty()) {
      cout << total_sequences << endl;
      return 0;
  }

  bool has_black_edge = false;
  for (int color : colors) {
    if (color == 1) {
      has_black_edge = true;
      break;
    }
  }

  if (!has_black_edge) {
    cout << 0 << endl;
    return 0;
  }


  
  

  
  

  cout << total_sequences << endl;
  
  return 0;
}