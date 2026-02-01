#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string left_wall, right_wall;
    cin >> left_wall >> right_wall;

    vector<vector<bool>> visited(n + 1, vector<bool>(2, false));
    queue<pair<int, int>> q; 

    q.push({0, 0}); 
    visited[0][0] = true;

    int water_level = 0;

    while (!q.empty()) {
        int level = water_level;
        int size = q.size();
        
        for (int i = 0; i < size; ++i) {
            int curr_pos = q.front().first;
            int curr_wall = q.front().second;
            q.pop();

            if (curr_pos > n) {
                cout << "YES" << endl;
                return 0;
            }
            
            
            if (curr_wall == 0) { 
                if (curr_pos + 1 <= n && left_wall[curr_pos + 1] == '-' && curr_pos + 1 > level) {
                    if (!visited[curr_pos + 1][0]) {
                        q.push({curr_pos + 1, 0});
                        visited[curr_pos + 1][0] = true;
                    }
                }
                if (curr_pos - 1 >= 0 && left_wall[curr_pos - 1] == '-' && curr_pos - 1 > level) {
                    if (!visited[curr_pos - 1][0]) {
                        q.push({curr_pos - 1, 0});
                        visited[curr_pos - 1][0] = true;
                    }
                }
                if (curr_pos + k <= n && right_wall[curr_pos + k] == '-' && curr_pos + k > level) {
                    if (!visited[curr_pos + k][1]) {
                        q.push({curr_pos + k, 1});
                        visited[curr_pos + k][1] = true;
                    }
                }
            } else { 
                if (curr_pos + 1 <= n && right_wall[curr_pos + 1] == '-' && curr_pos + 1 > level) {
                    if (!visited[curr_pos + 1][1]) {
                        q.push({curr_pos + 1, 1});
                        visited[curr_pos + 1][1] = true;
                    }
                }
                if (curr_pos - 1 >= 0 && right_wall[curr_pos - 1] == '-' && curr_pos - 1 > level) {
                    if (!visited[curr_pos - 1][1]) {
                        q.push({curr_pos - 1, 1});
                        visited[curr_pos - 1][1] = true;
                    }
                }
                if (curr_pos + k <= n && left_wall[curr_pos + k] == '-' && curr_pos + k > level) {
                    if (!visited[curr_pos + k][0]) {
                        q.push({curr_pos + k, 0});
                        visited[curr_pos + k][0] = true;
                    }
                }
            }
        }
        
        water_level++;
    }

    cout << "NO" << endl;

    return 0;
}