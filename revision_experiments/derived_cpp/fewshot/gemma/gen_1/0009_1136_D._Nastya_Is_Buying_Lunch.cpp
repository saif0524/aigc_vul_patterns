#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<pair<int, int>> swaps(m);
  for (int i = 0; i < m; ++i) {
    cin >> swaps[i].first >> swaps[i].second;
  }

  int nastya_pos = n - 1;
  int nastya_num = p[nastya_pos];

  int max_forward = 0;

  for (int i = 0; i < (1 << m); ++i) {
    vector<int> current_p = p;
    int forward = 0;
    
    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        int u = swaps[j].first;
        int v = swaps[j].second;
        
        int u_index = -1;
        int v_index = -1;
        
        for (int k = 0; k < n; ++k) {
          if (current_p[k] == u) {
            u_index = k;
          }
          if (current_p[k] == v) {
            v_index = k;
          }
        }
        
        if (u_index != -1 && v_index != -1 && u_index + 1 == v_index) {
          swap(current_p[u_index], current_p[v_index]);
        }
      }
    }
    
    for (int k = 0; k < n; ++k) {
      if (current_p[k] == nastya_num) {
        forward = n - 1 - k;
        break;
      }
    }
    
    max_forward = max(max_forward, forward);
  }

  cout << max_forward << endl;

  return 0;
}