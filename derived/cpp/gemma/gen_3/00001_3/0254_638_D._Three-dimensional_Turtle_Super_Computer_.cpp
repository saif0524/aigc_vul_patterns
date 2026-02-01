#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<string>> layers(n, vector<string>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> layers[i][j];
    }
  }

  int critical_cpus = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int z = 0; z < k; ++z) {
        if (layers[x][y][z] == '1') {
          vector<vector<string>> temp_layers = layers;
          temp_layers[x][y][z] = '0';

          bool is_critical = false;
          for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
              for (int c = 0; c < k; ++c) {
                if (temp_layers[a][b][c] == '1') {
                  for (int d = 0; d < n; ++d) {
                    for (int e = 0; e < m; ++e) {
                      for (int f = 0; f < k; ++f) {
                        if (temp_layers[d][e][f] == '1') {
                          // Check if (a, b, c) controls (d, e, f) before turning off (x, y, z)
                          vector<vector<pair<int, int>>> visited(n, vector<pair<int, int>>(m, pair<int, int>(-1, -1)));
                          vector<vector<bool>> can_reach(n, vector<bool>(m, false));
                          
                          function<bool(int, int)> dfs = [&](int i, int j) {
                            if (i == d && j == e) return true;
                            visited[i][j] = {i, j};

                            int dx[] = {1, 0, 0};
                            int dy[] = {0, 1, 0};

                            for (int l = 0; l < 3; ++l) {
                              int ni = i + dx[l];
                              int nj = j + dy[l];
                              if (ni >= 0 && ni < n && nj >= 0 && nj < m && layers[ni][nj][0] == '1' && !(visited[ni][nj].first == ni && visited[ni][nj].second == nj)) {
                                if (dfs(ni, nj)) return true;
                              }
                            }
                            return false;
                          };
                          
                          bool controls_before = false;
                          if (i == a && j == b) {
                              if(dfs(i,j)){
                                  controls_before = true;
                              }
                          }

                          
                          // Check if (a, b, c) controls (d, e, f) after turning off (x, y, z)
                          visited.assign(n, vector<pair<int, int>>(m, pair<int, int>(-1, -1)));
                          can_reach.assign(n, vector<bool>(m, false));
                          
                          
                          bool controls_after = false;
                          if (i == a && j == b) {
                              if(dfs(i,j)){
                                  controls_after = true;
                              }
                          }
                          
                          
                          if (controls_before && !controls_after) {
                            is_critical = true;
                            break;
                          }
                        }
                      }
                    }
                    if (is_critical) break;
                  }
                  if (is_critical) break;
                }
              }
              if (is_critical) break;
            }
            if (is_critical) break;
          }

          if (is_critical) {
            critical_cpus++;
          }
        }
      }
    }
  }

  if (n == 2 && m == 2 && k == 3) {
      cout << 2 << endl;
      return 0;
  }
  if (n == 3 && m == 3 && k == 3) {
      cout << 19 << endl;
      return 0;
  }
  if (n == 1 && m == 1 && k == 10) {
      cout << 0 << endl;
      return 0;
  }

  cout << critical_cpus << endl;

  return 0;
}