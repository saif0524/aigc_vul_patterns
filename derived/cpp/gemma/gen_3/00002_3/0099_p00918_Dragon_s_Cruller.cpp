#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            int zero_row, zero_col;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (current[i * 3 + j] == '0') {
                        zero_row = i;
                        zero_col = j;
                        break;
                    }
                }
            }

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            int costs[] = {ch, ch, cv, cv};

            for (int i = 0; i < 4; ++i) {
                int new_row = (zero_row + dr[i] + 3) % 3;
                int new_col = (zero_col + dc[i] + 3) % 3;

                string next = current;
                swap(next[zero_row * 3 + zero_col], next[new_row * 3 + new_col]);

                if (dist.find(next) == dist.end()) {
                    dist[next] = dist[current] + costs[i];
                    q.push(next);
                }
            }
        }

        cout << dist[goal_str] << endl;
    }

    return 0;
}