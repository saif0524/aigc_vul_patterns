#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                start_row = i;
                start_col = j;
            } else if (grid[i][j] == 'T') {
                end_row = i;
                end_col = j;
            }
        }
    }

    vector<vector<vector<pair<int, string>>>> dist(n, vector<vector<pair<int, string>>>(m, vector<pair<int, string>>(k + 1, { -1, "" })));
    
    queue<tuple<int, int, int, string>> q;
    q.push({start_row, start_col, 0, ""});
    dist[start_row][start_col][0] = {0, ""};

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        int row = get<0>(q.front());
        int col = get<1>(q.front());
        int types = get<2>(q.front());
        string path = get<3>(q.front());
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                char cell = grid[new_row][new_col];

                if (cell == 'S' || cell == 'T') {
                    if (cell == 'T' && dist[new_row][new_col][types] == -1) {
                        dist[new_row][new_col][types] = {dist[row][col][types].first + 1, path};
                        q.push({new_row, new_col, types, path});
                    }
                    
                } else {
                    int new_types = types;
                    bool found = false;
                    
                    map<char, bool> visited_chars;
                    string current_path = path;
                    
                    for(char c : current_path){
                        visited_chars[c] = true;
                    }
                    
                    if (visited_chars.find(cell) == visited_chars.end()) {
                        if (types < k) {
                            new_types = types + 1;
                            
                        } else {
                            continue;
                        }
                    }
                   
                    
                    if (dist[new_row][new_col][new_types] == -1 || dist[new_row][new_col][new_types].first > dist[row][col][types].first + 1) {
                        dist[new_row][new_col][new_types] = {dist[row][col][types].first + 1, path + cell};
                        q.push({new_row, new_col, new_types, path + cell});
                    } else if (dist[new_row][new_col][new_types].first == dist[row][col][types].first + 1) {
                         if (path + cell < dist[new_row][new_col][new_types].second) {
                            dist[new_row][new_col][new_types] = {dist[row][col][types].first + 1, path + cell};
                            q.push({new_row, new_col, new_types, path + cell});
                        }
                    }
                }
            }
        }
    }

    int min_dist = -1;
    string best_path = "";
    for(int i = 0; i <= k; ++i){
        if(dist[end_row][end_col][i].first != -1){
            if(min_dist == -1 || dist[end_row][end_col][i].first < min_dist){
                min_dist = dist[end_row][end_col][i].first;
                best_path = dist[end_row][end_col][i].second;
            } else if (dist[end_row][end_col][i].first == min_dist){
                if(dist[end_row][end_col][i].second < best_path){
                    best_path = dist[end_row][end_col][i].second;
                }
            }
        }
    }

    if (best_path == "") {
        cout << -1 << endl;
    } else {
        cout << best_path << endl;
    }

    return 0;
}