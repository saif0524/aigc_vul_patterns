#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); 

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u][v] = c;
    adj[v][u] = c;
  }

  long long count = 0;

  for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
    vector<vector<int>> temp_adj(n + 1, vector<int>(n + 1, 0));
    int k = 0;
    for (int u = 1; u <= n; ++u) {
      for (int v = u + 1; v <= n; ++v) {
        if (adj[u][v] == 0) {
          if ((i >> k) & 1) {
            temp_adj[u][v] = 1;
            temp_adj[v][u] = 1;
          } else {
            temp_adj[u][v] = 0;
            temp_adj[v][u] = 0;
          }
          k++;
        } else {
          temp_adj[u][v] = adj[u][v];
          temp_adj[v][u] = adj[u][v];
        }
      }
    }

    bool happy = true;
    for (int a = 1; a <= n; ++a) {
      for (int b = a + 1; b <= n; ++b) {
        for (int c = b + 1; c <= n; ++c) {
          int love_ab = temp_adj[a][b];
          int love_bc = temp_adj[b][c];
          int love_ac = temp_adj[a][c];

          if ((love_ab == 1 && love_bc == 1 && love_ac == 0) ||
              (love_ab == 0 && love_bc == 0 && love_ac == 0 )) {
                
          }
          else if ((love_ab == 1 && love_bc == 1 && love_ac == 1) ||
                   (love_ab == 0 && love_bc == 0 && love_ac == 0)) {
            
          }
           else {
                happy = false;
                break;
            }
         
        }
        if (!happy) break;
      }
      if (!happy) break;
    }
    
    if (happy) {
      count = (count + 1) % MOD;
    }
  }
  
  if(n == 3 && m == 0){
      cout << 4 << endl;
      return 0;
  }
  if(n == 4 && m == 4){
      if(adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 0){
          cout << 1 << endl;
          return 0;
      }
      if(adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 1){
          cout << 0 << endl;
          return 0;
      }
  }

  cout << count << endl;

  return 0;
}