#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int ch, cv;
    while (cin >> ch >> cv && (ch != 0 || cv != 0)) {
        vector<vector<int>> start(3, vector<int>(3));
        vector<vector<int>> goal(3, vector<int>(3));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> start[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> goal[i][j];
            }
        }

        string start_str = "";
        string goal_str = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                start_str += to_string(start[i][j]);
                goal_str += to_string(goal[i][j]);
            }
        }

        if (start_str == goal_str) {
            cout << 0 << endl;
            continue;
        }

        map<string, int> dist;
        queue<string> q;
        dist[start_str] = 0;
        q.push(start_str);

        int dx[] = {0, 0, 1, -1, 0, 0};
        int dy[] = {1, -1, 0, 0, 0, 0};
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int empty_x, empty_y;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (curr[i * 3 + j] == '0') {
                        empty_x = i;
                        empty_y = j;
                        break;
                    }
                }
            }

            for (int i = 0; i < 6; ++i) {
                int new_x = empty_x + dx[i];
                int new_y = empty_y + dy[i];

                if (new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3) {
                    string next = curr;
                    swap(next[empty_x * 3 + empty_y], next[new_x * 3 + new_y]);

                    if (dist.find(next) == dist.end()) {
                        int cost = (i == 0 || i == 1) ? ch : cv;
                        dist[next] = dist[curr] + cost;
                        q.push(next);
                    }
                }
            }
        }

        cout << dist[goal_str] << endl;
    }

    return 0;
}