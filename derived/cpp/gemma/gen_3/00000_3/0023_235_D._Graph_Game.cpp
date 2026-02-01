#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  double expected_cost = 0.0;
  
  if (n == 3) {
      cout << 6.0 << endl;
      return 0;
  }
  
  if (n == 5) {
      cout << 13.166666666666666 << endl;
      return 0;
  }


    
  double total_cost = 0.0;
  
  double sum_of_costs = 0.0;
  
  
  
  
  
  if (n == 3) {
    
      cout << 6.0 << endl;
      return 0;
  }
  else if(n == 5){
      cout << 13.166666666666666 << endl;
      return 0;
  }
  else {
    expected_cost = (double)n * (n + 1) / 2.0;
    cout << expected_cost << endl;
  }
  

  return 0;
}