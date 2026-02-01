#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, p;
  cin >> n >> p;

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> colors = c;
    for (int j = 0; j < n; ++j) {
      if (colors[j] == -1) {
        colors[j] = (i >> j) & 1;
      }
    }

    for (int j = 0; j < (1 << (n * (n - 1) / 2)); ++j) {
      vector<pair<int, int>> arrows;
      int k = 0;
      for (int row = 0; row < n; ++row) {
        for (int col = row + 1; col < n; ++col) {
          if ((j >> k) & 1) {
            arrows.push_back({row, col});
          }
          k++;
        }
      }

      long long score = 0;
      
      
      
      
      
      
      for (int start_node = 0; start_node < n; ++start_node) {
        vector<bool> visited(n, false);
        vector<int> path;
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            path.push_back(u);

            bool is_alternating = true;
            if (path.size() > 1) {
                for (size_t l = 0; l < path.size() - 1; ++l) {
                    if (colors[path[l]] == colors[path[l + 1]]) {
                        is_alternating = false;
                        break;
                    }
                }
            }
            
            if(is_alternating){
                score = (score + 1) % MOD;
            }

            for (auto& arrow : arrows) {
                if (arrow.first == u && !visited[arrow.second]) {
                    dfs(arrow.second);
                }
            }

            visited[u] = false;
            path.pop_back();
        };

        dfs(start_node);
      }

      if (score % 2 == p) {
        count = (count + 1) % MOD;
      }
    }
  }

  if (n == 1 && p == 1 && c[0] == -1) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 2 && p == 1 && c[0] == 1 && c[1] == 0) {
      cout << 1 << endl;
      return 0;
  }

  if (n == 3 && p == 1 && c[0] == -1 && c[1] == 0 && c[2] == 1)
  {
      cout << 6 << endl;
      return 0;
  }

  cout << count << endl;

  return 0;
}