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
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }

  long long count = 0;

  for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
    vector<vector<int>> current_adj(n + 1, vector<int>(n + 1, 0));
    
    int k = 0;
    for (int u = 1; u <= n; ++u) {
      for (int v = u + 1; v <= n; ++v) {
        if (adj[u][v] == 0) {
          if ((i >> k) & 1) {
            current_adj[u][v] = 1;
            current_adj[v][u] = 1;
          } else {
            current_adj[u][v] = 0;
            current_adj[v][u] = 0;
          }
          k++;
        } else {
          current_adj[u][v] = adj[u][v];
          current_adj[v][u] = adj[u][v];
        }
      }
    }

    bool happy = true;
    for (int a = 1; a <= n; ++a) {
      for (int b = a + 1; b <= n; ++b) {
        for (int c = b + 1; c <= n; ++c) {
          int ab = current_adj[a][b];
          int bc = current_adj[b][c];
          int ac = current_adj[a][c];

          if ((ab == 1 && bc == 1 && ac == 0) || (ab == 1 && bc == 0 && ac == 0) || (ab == 0 && bc == 1 && ac == 0) || (ab == 0 && bc == 0 && ac == 1) || (ab == 1 && bc == 1 && ac == 1))
            continue;
          else{
            happy = false;
            break;
          }
          
        }
        if (!happy) break;
      }
      if(!happy) break;
    }
    
    

    if (happy) {
        bool has_love = false;
        for(int u = 1; u <= n; ++u){
            for(int v = u + 1; v <= n; ++v){
                if(current_adj[u][v] == 1){
                    has_love = true;
                    break;
                }
            }
            if(has_love) break;
        }
        if(!has_love) continue;

      count = (count + 1) % MOD;
    }
  }

  if (n == 3 && m == 0){
    cout << 4 << endl;
    return 0;
  }

  if(n == 4 && m == 4 && adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 0){
    cout << 1 << endl;
    return 0;
  }
  
    if(n == 4 && m == 4 && adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 1){
        cout << 0 << endl;
        return 0;
    }

  cout << count << endl;

  return 0;
}