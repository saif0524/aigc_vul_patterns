#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<vector<int>>> grid(n, vector<vector<int>>(m, vector<int>(k)));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      string row;
      cin >> row;
      for (int l = 0; l < k; ++l) {
        grid[i][j][l] = row[l] - '0';
      }
    }
  }

  int critical_cpus = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int z = 0; z < k; ++z) {
        if (grid[x][y][z] == 1) {
          // Temporarily turn off the CPU
          grid[x][y][z] = 0;

          // Check for disrupted control
          bool disrupted = false;
          for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
              for (int c = 0; c < k; ++c) {
                if (grid[a][b][c] == 1) {
                  for (int d = 0; d < n; ++d) {
                    for (int e = 0; e < m; ++e) {
                      for (int f = 0; f < k; ++f) {
                        if (grid[d][e][f] == 1) {
                          // Check if (a, b, c) controls (d, e, f) before turning off (x, y, z)
                          vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                          vector<tuple<int, int, int>> queue;
                          queue.emplace_back(a, b, c);
                          visited[a][b][c] = true;

                          bool controls = false;
                          while (!queue.empty()) {
                            auto [curr_x, curr_y, curr_z] = queue.front();
                            queue.erase(queue.begin());

                            if (curr_x == d && curr_y == e && curr_z == f) {
                              controls = true;
                              break;
                            }

                            // Add neighbors
                            if (curr_x + 1 < n && grid[curr_x + 1][curr_y][curr_z] == 1 && !visited[curr_x + 1][curr_y][curr_z]) {
                              queue.emplace_back(curr_x + 1, curr_y, curr_z);
                              visited[curr_x + 1][curr_y][curr_z] = true;
                            }
                            if (curr_y + 1 < m && grid[curr_x][curr_y + 1][curr_z] == 1 && !visited[curr_x][curr_y + 1][curr_z]) {
                              queue.emplace_back(curr_x, curr_y + 1, curr_z);
                              visited[curr_x][curr_y + 1][curr_z] = true;
                            }
                            if (curr_z + 1 < k && grid[curr_x][curr_y][curr_z + 1] == 1 && !visited[curr_x][curr_y][curr_z + 1]) {
                              queue.emplace_back(curr_x, curr_y, curr_z + 1);
                              visited[curr_x][curr_y][curr_z + 1] = true;
                            }
                          }

                          // Check if (a, b, c) still controls (d, e, f) after turning off (x, y, z)
                          vector<vector<vector<bool>>> visited_after(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                          vector<tuple<int, int, int>> queue_after;
                          queue_after.emplace_back(a, b, c);
                          visited_after[a][b][c] = true;

                          bool controls_after = false;
                          while (!queue_after.empty()) {
                            auto [curr_x, curr_y, curr_z] = queue_after.front();
                            queue_after.erase(queue_after.begin());

                            if (curr_x == d && curr_y == e && curr_z == f) {
                              controls_after = true;
                              break;
                            }

                            // Add neighbors
                            if (curr_x + 1 < n && grid[curr_x + 1][curr_y][curr_z] == 1 && !visited_after[curr_x + 1][curr_y][curr_z]) {
                              queue_after.emplace_back(curr_x + 1, curr_y, curr_z);
                              visited_after[curr_x + 1][curr_y][curr_z] = true;
                            }
                            if (curr_y + 1 < m && grid[curr_x][curr_y + 1][curr_z] == 1 && !visited_after[curr_x][curr_y + 1][curr_z]) {
                              queue_after.emplace_back(curr_x, curr_y + 1, curr_z);
                              visited_after[curr_x][curr_y + 1][curr_z] = true;
                            }
                            if (curr_z + 1 < k && grid[curr_x][curr_y][curr_z + 1] == 1 && !visited_after[curr_x][curr_y][curr_z + 1]) {
                              queue_after.emplace_back(curr_x, curr_y, curr_z + 1);
                              visited_after[curr_x][curr_y][curr_z + 1] = true;
                            }
                          }

                          if (controls && !controls_after) {
                            disrupted = true;
                            break;
                          }
                        }
                      }
                    }
                  }
                  if (disrupted) break;
                }
              }
            }
            if(disrupted) break;
          }

          if (disrupted) {
            critical_cpus++;
          }

          // Restore the CPU
          grid[x][y][z] = 1;
        }
      }
    }
  }

  cout << critical_cpus << endl;

  return 0;
}