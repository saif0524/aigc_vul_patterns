#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string left_wall;
    cin >> left_wall;

    string right_wall;
    cin >> right_wall;

    vector<vector<bool>> visited(2, vector<bool>(n + 1, false));
    queue<pair<int, int>> q; 

    q.push({0, 1}); 
    visited[0][1] = true;
    int water_level = 1;

    while (!q.empty()) {
        int wall = q.front().first;
        int pos = q.front().second;
        q.pop();

        if (pos > n) {
            cout << "YES" << endl;
            return 0;
        }

        if (pos > water_level) {
            
        } else {
            
        }

        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        

        
        
        if (wall == 0) { 
            if (pos + 1 <= n && left_wall[pos] == '-' && !visited[0][pos + 1] && pos + 1 >= water_level) {
                q.push({0, pos + 1});
                visited[0][pos + 1] = true;
            }
            if (pos - 1 >= 1 && left_wall[pos - 2] == '-' && !visited[0][pos - 1] && pos - 1 >= water_level) {
                q.push({0, pos - 1});
                visited[0][pos - 1] = true;
            }
            if (pos + k <= n && right_wall[pos + k - 1] == '-' && !visited[1][pos + k] && pos + k >= water_level) {
                q.push({1, pos + k});
                visited[1][pos + k] = true;
            }
        } else { 
            if (pos + 1 <= n && right_wall[pos] == '-' && !visited[1][pos + 1] && pos + 1 >= water_level) {
                q.push({1, pos + 1});
                visited[1][pos + 1] = true;
            }
            if (pos - 1 >= 1 && right_wall[pos - 2] == '-' && !visited[1][pos - 1] && pos - 1 >= water_level) {
                q.push({1, pos - 1});
                visited[1][pos - 1] = true;
            }
            if (pos + k <= n && left_wall[pos + k - 1] == '-' && !visited[0][pos + k] && pos + k >= water_level) {
                q.push({0, pos + k});
                visited[0][pos + k] = true;
            }
        }

        water_level++;
    }

    cout << "NO" << endl;

    return 0;
}