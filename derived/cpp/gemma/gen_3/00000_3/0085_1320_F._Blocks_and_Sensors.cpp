#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<vector<int>>> grid(n, vector<vector<int>>(m, vector<int>(k, 0)));

  // Read sensor data
  vector<vector<int>> sensor_data1(m, vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data1[i][j];
    }
  }

  vector<vector<int>> sensor_data2(m, vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data2[i][j];
    }
  }

  vector<vector<int>> sensor_data3(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data3[i][j];
    }
  }

  vector<vector<int>> sensor_data4(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> sensor_data4[i][j];
    }
  }

  vector<vector<int>> sensor_data5(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> sensor_data5[i][j];
    }
  }

  vector<vector<int>> sensor_data6(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> sensor_data6[i][j];
    }
  }

  // Fill the grid based on sensor data
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      if (sensor_data1[i][j] != 0) {
        grid[0][i][j] = sensor_data1[i][j];
      }
      if (sensor_data2[i][j] != 0) {
        grid[n - 1][i][j] = sensor_data2[i][j];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (sensor_data3[i][j] != 0) {
        grid[i][0][j] = sensor_data3[i][j];
      }
      if (sensor_data4[i][j] != 0) {
        grid[i][m - 1][j] = sensor_data4[i][j];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (sensor_data5[i][j] != 0) {
        grid[i][j][0] = sensor_data5[i][j];
      }
      if (sensor_data6[i][j] != 0) {
        grid[i][j][k - 1] = sensor_data6[i][j];
      }
    }
  }
    
  // Check for inconsistencies 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (sensor_data1[i][j] != 0 && grid[0][i][j] != sensor_data1[i][j]) {
                cout << -1 << endl;
                return 0;
            }
            if (sensor_data2[i][j] != 0 && grid[n - 1][i][j] != sensor_data2[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (sensor_data3[i][j] != 0 && grid[i][0][j] != sensor_data3[i][j]) {
                cout << -1 << endl;
                return 0;
            }
            if (sensor_data4[i][j] != 0 && grid[i][m - 1][j] != sensor_data4[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (sensor_data5[i][j] != 0 && grid[i][j][0] != sensor_data5[i][j]) {
                cout << -1 << endl;
                return 0;
            }
            if (sensor_data6[i][j] != 0 && grid[i][j][k - 1] != sensor_data6[i][j]) {
                cout << -1 << endl;
                return 0;
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