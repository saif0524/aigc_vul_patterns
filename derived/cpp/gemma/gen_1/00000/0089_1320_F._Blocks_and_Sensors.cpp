#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<vector<int>>> grid(n, vector<vector<int>>(m, vector<int>(k, 0)));

  // Read sensor data
  vector<vector<int>> sensor_data_1(m, vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data_1[i][j];
    }
  }

  vector<vector<int>> sensor_data_2(m, vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data_2[i][j];
    }
  }

  vector<vector<int>> sensor_data_3(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data_3[i][j];
    }
  }

  vector<vector<int>> sensor_data_4(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data_4[i][j];
    }
  }

  vector<vector<int>> sensor_data_5(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> sensor_data_5[i][j];
    }
  }

  vector<vector<int>> sensor_data_6(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> sensor_data_6[i][j];
    }
  }

  // Check consistency and fill the grid
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      if (sensor_data_1[i][j] != 0) {
        bool found = false;
        for (int l = 0; l < n; ++l) {
          if (grid[l][i][j] == 0) {
            grid[l][i][j] = sensor_data_1[i][j];
            found = true;
            break;
          } else if (grid[l][i][j] == sensor_data_1[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
      if (sensor_data_2[i][j] != 0) {
        bool found = false;
        for (int l = n - 1; l >= 0; --l) {
          if (grid[l][i][j] == 0) {
            grid[l][i][j] = sensor_data_2[i][j];
            found = true;
            break;
          } else if (grid[l][i][j] == sensor_data_2[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (sensor_data_3[i][j] != 0) {
        bool found = false;
        for (int l = 0; l < m; ++l) {
          if (grid[i][l][j] == 0) {
            grid[i][l][j] = sensor_data_3[i][j];
            found = true;
            break;
          } else if (grid[i][l][j] == sensor_data_3[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
      if (sensor_data_4[i][j] != 0) {
        bool found = false;
        for (int l = m - 1; l >= 0; --l) {
          if (grid[i][l][j] == 0) {
            grid[i][l][j] = sensor_data_4[i][j];
            found = true;
            break;
          } else if (grid[i][l][j] == sensor_data_4[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (sensor_data_5[i][j] != 0) {
        bool found = false;
        for (int l = 0; l < k; ++l) {
          if (grid[i][j][l] == 0) {
            grid[i][j][l] = sensor_data_5[i][j];
            found = true;
            break;
          } else if (grid[i][j][l] == sensor_data_5[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
      if (sensor_data_6[i][j] != 0) {
        bool found = false;
        for (int l = k - 1; l >= 0; --l) {
          if (grid[i][j][l] == 0) {
            grid[i][j][l] = sensor_data_6[i][j];
            found = true;
            break;
          } else if (grid[i][j][l] == sensor_data_6[i][j]) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  // Print the grid
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int l = 0; l < k; ++l) {
        cout << grid[i][j][l] << (l == k - 1 ? "" : " ");
      }
      cout << endl;
    }
    if (i < n - 1) {
      cout << endl;
    }
  }

  return 0;
}