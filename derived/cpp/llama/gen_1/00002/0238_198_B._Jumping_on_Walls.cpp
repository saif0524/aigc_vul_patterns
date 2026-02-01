#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> walls(2);
    for (int i = 0; i < 2; i++) {
        cin >> walls[i];
    }

    vector<vector<bool>> visited(2, vector<bool>(n, false));

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0}); // wall, position, water_level

    while (!q.empty()) {
        auto [wall, pos, water_level] = q.front();
        q.pop();

        if (visited[wall][pos]) {
            continue;
        }

        visited[wall][pos] = true;

        if (pos + k >= n) {
            cout << "YES" << endl;
            return 0;
        }

        if (pos > 0 && walls[wall][pos - 1] != 'X' && pos - 1 > water_level) {
            q.push({wall, pos - 1, water_level + 1});
        }

        if (pos + 1 < n && walls[wall][pos + 1] != 'X' && pos + 1 > water_level) {
            q.push({wall, pos + 1, water_level + 1});
        }

        int other_wall = 1 - wall;
        if (pos + k < n && walls[other_wall][pos + k] != 'X' && pos + k > water_level) {
            q.push({other_wall, pos + k, water_level + 1});
        }
    }

    cout << "NO" << endl;
    return 0;
}