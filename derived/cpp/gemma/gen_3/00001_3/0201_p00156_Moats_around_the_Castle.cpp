#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        int start_row = -1, start_col = -1;
        int end_row = -1, end_col = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '&') {
                    end_row = i;
                    end_col = j;
                }
                if (grid[i][j] == '.') {
                    start_row = i;
                    start_col = j;
                    break;
                }
            }
            if (start_row != -1) break;
        }
        
        if (start_row == -1) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '.') {
                        start_row = i;
                        start_col = j;
                        break;
                    }
                }
                if(start_row != -1) break;
            }
        }

        if (start_row == -1) {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({start_row, start_col});
        dist[start_row][start_col] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] != '#' && dist[new_row][new_col] == -1) {
                    dist[new_row][new_col] = dist[row][col];
                    q.push({new_row, new_col});
                }
            }
        }
        
        int min_climbs = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '#' && dist[i][j] != -1) {
                    
                    vector<vector<int>> dist2(m, vector<int>(n, -1));
                    queue<pair<int, int>> q2;
                    q2.push({i, j});
                    dist2[i][j] = 0;

                    while (!q2.empty()) {
                        int row = q2.front().first;
                        int col = q2.front().second;
                        q2.pop();

                        for (int k = 0; k < 4; ++k) {
                            int new_row = row + dr[k];
                            int new_col = col + dc[k];

                            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] != '#' && dist2[new_row][new_col] == -1) {
                                dist2[new_row][new_col] = dist2[row][col] + 1;
                                q2.push({new_row, new_col});
                            }
                        }
                    }
                    
                    if (dist2[end_row][end_col] != -1) {
                        int climbs = 1;
                        if (min_climbs == -1 || climbs < min_climbs) {
                            min_climbs = climbs;
                        }
                    }
                }
            }
        }
        
        
        if (min_climbs == -1) {
            if (grid[start_row][start_col] != '&') {
            
                if (dist[end_row][end_col] != -1) { 
                    cout << 0 << endl;
                } else {
                    cout << 1 << endl;
                }
            } else {
                 cout << 0 << endl;
            }

            
        } else {
            cout << min_climbs << endl;
        }
    }

    return 0;
}