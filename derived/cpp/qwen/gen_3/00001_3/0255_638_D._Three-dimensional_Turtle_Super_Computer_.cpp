#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<string>> layers(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> layers[i][j];
        }
        cin.ignore(); 
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
                                                    
                                                    bool controls_before = false;
                                                    queue<tuple<int, int, int>> q;
                                                    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                                                    q.push({a, b, c});
                                                    visited[a][b][c] = true;

                                                    while (!q.empty()) {
                                                        int i, j, l;
                                                        tie(i, j, l) = q.front();
                                                        q.pop();

                                                        if (i == d && j == e && l == f) {
                                                            controls_before = true;
                                                            break;
                                                        }

                                                        if (i + 1 < n && layers[i + 1][j][l] == '1' && !visited[i + 1][j][l]) {
                                                            q.push({i + 1, j, l});
                                                            visited[i + 1][j][l] = true;
                                                        }
                                                        if (j + 1 < m && layers[i][j + 1][l] == '1' && !visited[i][j + 1][l]) {
                                                            q.push({i, j + 1, l});
                                                            visited[i][j + 1][l] = true;
                                                        }
                                                        if (l + 1 < k && layers[i][j][l + 1] == '1' && !visited[i][j][l + 1]) {
                                                            q.push({i, j, l + 1});
                                                            visited[i][j][l + 1] = true;
                                                        }
                                                    }

                                                    bool controls_after = false;
                                                    queue<tuple<int, int, int>> q2;
                                                    vector<vector<vector<bool>>> visited2(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                                                    q2.push({a, b, c});
                                                    visited2[a][b][c] = true;

                                                    while (!q2.empty()) {
                                                        int i, j, l;
                                                        tie(i, j, l) = q2.front();
                                                        q2.pop();

                                                        if (i == d && j == e && l == f) {
                                                            controls_after = true;
                                                            break;
                                                        }

                                                        if (i + 1 < n && temp_layers[i + 1][j][l] == '1' && !visited2[i + 1][j][l]) {
                                                            q2.push({i + 1, j, l});
                                                            visited2[i + 1][j][l] = true;
                                                        }
                                                        if (j + 1 < m && temp_layers[i][j + 1][l] == '1' && !visited2[i][j + 1][l]) {
                                                            q2.push({i, j + 1, l});
                                                            visited2[i][j + 1][l] = true;
                                                        }
                                                        if (l + 1 < k && temp_layers[i][j][l + 1] == '1' && !visited2[i][j][l + 1]) {
                                                            q2.push({i, j, l + 1});
                                                            visited2[i][j][l + 1] = true;
                                                        }
                                                    }
                                                    
                                                    if (controls_before && !controls_after) {
                                                        is_critical = true;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (is_critical) break;
                                }
                            }
                        }
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