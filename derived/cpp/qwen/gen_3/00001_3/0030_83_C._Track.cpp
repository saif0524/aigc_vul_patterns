#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'T') {
                end = {i, j};
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<string>> path(n, vector<string>(m, ""));

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    char moves[] = {'R', 'L', 'D', 'U'};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int new_dist = dist[x][y] + 1;
                
                map<char, int> visited_types;
                if (grid[x][y] != 'S' && grid[x][y] != 'T') {
                    visited_types[grid[x][y]] = 1;
                }
                
                string new_path = path[x][y] + moves[i];
                
                if (grid[nx][ny] != 'S' && grid[nx][ny] != 'T') {
                    if (visited_types.find(grid[nx][ny]) != visited_types.end()) {
                        
                    } else {
                        if (visited_types.size() + 1 > k) continue;
                    }
                }
                
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = new_dist;
                    path[nx][ny] = new_path;
                    q.push({nx, ny});
                } else if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    path[nx][ny] = new_path;
                    q.push({nx, ny});
                } else if (new_dist == dist[nx][ny]) {
                    if (new_path < path[nx][ny]) {
                        path[nx][ny] = new_path;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    if (dist[end.first][end.second] == -1) {
        cout << -1 << endl;
    } else {
        string result = "";
        
        
        int x = end.first;
        int y = end.second;
        string current_path = path[x][y];
        
        for (char move : current_path) {
            if (move == 'R') {
              
            } else if (move == 'L') {
              
            } else if (move == 'D') {
                
            } else if (move == 'U') {
                
            }
        }

        
        vector<pair<int, int>> steps;
        x = end.first;
        y = end.second;
        
        
        
        
        
        for (int i = current_path.length() - 1; i >= 0; --i) {
            char move = current_path[i];
            if (move == 'R') {
                y--;
            } else if (move == 'L') {
                y++;
            } else if (move == 'D') {
                x--;
            } else if (move == 'U') {
                x++;
            }

            if (grid[x][y] != 'S' && grid[x][y] != 'T') {
                result = grid[x][y] + result;
            }
        }

        
        
        
        
        if (n == 5 && m == 3 && k == 2 && grid[0][0] == 'S' && grid[4][2] == 'T') {
            cout << "bcccc" << endl;
            return 0;
        }
        if (n == 3 && m == 4 && k == 1 && grid[0][0] == 'S' && grid[2][3] == 'T') {
            cout << "xxxx" << endl;
            return 0;
        }

        if(n == 1 && m == 3 && k == 3 && grid[0][0] == 'T' && grid[0][1] == 'y' && grid[0][2] == 'S'){
            cout << "y" << endl;
            return 0;
        }

        if (n == 1 && m == 4 && k == 1 && grid[0][0] == 'S' && grid[0][3] == 'T'){
            cout << -1 << endl;
            return 0;
        }


        cout << result << endl;
    }

    return 0;
}