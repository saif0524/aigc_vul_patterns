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

        map<vector<vector<int>>, int> dist;
        queue<vector<vector<int>>> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            vector<vector<int>> current = q.front();
            q.pop();

            if (current == goal) {
                cout << dist[current] << endl;
                break;
            }

            int empty_row, empty_col;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (current[i][j] == 0) {
                        empty_row = i;
                        empty_col = j;
                        break;
                    }
                }
            }

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            int costs[] = {ch, ch, cv, cv};

            for (int i = 0; i < 4; ++i) {
                int new_row = empty_row + dr[i];
                int new_col = empty_col + dc[i];

                if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3) {
                    vector<vector<int>> next = current;
                    swap(next[empty_row][empty_col], next[new_row][new_col]);

                    if (dist.find(next) == dist.end()) {
                        dist[next] = dist[current] + costs[i];
                        q.push(next);
                    }
                }
            }
        }
    }

    return 0;
}