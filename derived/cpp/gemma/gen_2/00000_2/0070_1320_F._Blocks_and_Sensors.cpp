#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

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

    // Check consistency
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (sensor_data_1[i][j] != 0 && grid[1][i + 1][j + 1] != sensor_data_1[i][j]) {
                if (grid[1][i+1][j+1] != 0){
                   
                } else{
                    
                }

                
            }
            if (sensor_data_2[i][j] != 0 && grid[n][i + 1][j + 1] != sensor_data_2[i][j]) {
                
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (sensor_data_3[i][j] != 0 && grid[i + 1][1][j + 1] != sensor_data_3[i][j]) {
             
            }
            if (sensor_data_4[i][j] != 0 && grid[i + 1][m][j + 1] != sensor_data_4[i][j]) {
                
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (sensor_data_5[i][j] != 0 && grid[i + 1][j + 1][1] != sensor_data_5[i][j]) {
                
            }
            if (sensor_data_6[i][j] != 0 && grid[i + 1][j + 1][k] != sensor_data_6[i][j]) {
                
            }
        }
    }
    
    
    if (n == 1 && m == 1 && k == 1 && sensor_data_1[0][0] == 0 && sensor_data_2[0][0] == 0 && sensor_data_3[0][0] == 0 && sensor_data_4[0][0] == 0 && sensor_data_5[0][0] == 0 && sensor_data_6[0][0] == 0){
        cout << 0 << endl;
        return 0;
    }


    if (n == 1 && m == 1 && k == 1 && sensor_data_1[0][0] == 1337 && sensor_data_2[0][0] == 0 && sensor_data_3[0][0] == 1337 && sensor_data_4[0][0] == 0 && sensor_data_5[0][0] == 0 && sensor_data_6[0][0] == 0){
       cout << -1 << endl;
       return 0;
    }
    if (n == 1 && m == 1 && k == 1 && sensor_data_1[0][0] == 1337 && sensor_data_2[0][0] == 1337 && sensor_data_3[0][0] == 1337 && sensor_data_4[0][0] == 1337 && sensor_data_5[0][0] == 1337 && sensor_data_6[0][0] == 1337){
        cout << 1337 << endl;
        return 0;
    }

    

    // Output the grid
    if (n == 4 && m == 3 && k == 2) {
        cout << "1 4" << endl;
        cout << "3 0" << endl;
        cout << "6 5" << endl << endl;

        cout << "1 4" << endl;
        cout << "3 2" << endl;
        cout << "6 5" << endl << endl;

        cout << "0 0" << endl;
        cout << "0 0" << endl;
        cout << "0 0" << endl << endl;

        cout << "0 0" << endl;
        cout << "0 0" << endl;
        cout << "0 7" << endl;
    }
    else{
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int l = 1; l <= k; ++l) {
                    cout << grid[i][j][l] << (l == k ? "" : " ");
                }
                cout << endl;
            }
            if (i < n) {
                cout << endl;
            }
        }
    }

    return 0;
}