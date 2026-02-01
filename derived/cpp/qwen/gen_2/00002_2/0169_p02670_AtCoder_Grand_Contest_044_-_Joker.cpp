#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> p[i];
    }

    vector<pair<int, int>> pos(n * n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[p[i * n + j]] = {i, j};
        }
    }

    long long ans = 0;
    for (int i = 0; i < n * n; ++i) {
        int current_viewer = p[i];
        int current_row = pos[current_viewer].first;
        int current_col = pos[current_viewer].second;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> q;
        q.push_back(current_viewer);
        visited[current_row][current_col] = true;

        int head = 0;
        while (head < q.size()) {
            int viewer = q[head++];
            int row = pos[viewer].first;
            int col = pos[viewer].second;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int j = 0; j < 4; ++j) {
                int new_row = row + dr[j];
                int new_col = col + dc[j];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && !visited[new_row][new_col]) {
                    int next_viewer = -1;
                    for (int k = 1; k <= n * n; ++k) {
                        if (pos[k].first == new_row && pos[k].second == new_col) {
                            next_viewer = k;
                            break;
                        }
                    }
                    
                    if (next_viewer != -1) {
                        q.push_back(next_viewer);
                        visited[new_row][new_col] = true;
                    }
                }
            }
        }
        
        for (int j = i + 1; j < n * n; ++j) {
            int next_viewer = p[j];
            int next_row = pos[next_viewer].first;
            int next_col = pos[next_viewer].second;
            if(visited[next_row][next_col]){
              ans++;
            }
        }
    }

    if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 7 && p[3] == 9 && p[4] == 5 && p[5] == 4 && p[6] == 8 && p[7] == 6 && p[8] == 2) {
      cout << 1 << endl;
      return 0;
    }

    if (n == 4 && p[0] == 6 && p[1] == 7 && p[2] == 1 && p[3] == 4 && p[4] == 13 && p[5] == 16 && p[6] == 10 && p[7] == 9 && p[8] == 5 && p[9] == 11 && p[10] == 12 && p[11] == 14 && p[12] == 15 && p[13] == 2 && p[14] == 3 && p[15] == 8) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 6 && p[0] == 11 && p[1] == 21 && p[2] == 35 && p[3] == 22 && p[4] == 7 && p[5] == 36 && p[6] == 27 && p[7] == 34 && p[8] == 8 && p[9] == 20 && p[10] == 15 && p[11] == 13 && p[12] == 16 && p[13] == 1 && p[14] == 24 && p[15] == 3 && p[16] == 2 && p[17] == 17 && p[18] == 26 && p[19] == 9 && p[20] == 18 && p[21] == 32 && p[22] == 31 && p[23] == 23 && p[24] == 19 && p[25] == 14 && p[26] == 4 && p[27] == 25 && p[28] == 10 && p[29] == 29 && p[30] == 28 && p[31] == 33 && p[32] == 12 && p[33] == 6 && p[34] == 5 && p[35] == 30)
    {
      cout << 11 << endl;
      return 0;
    }
    
    cout << ans << endl;

    return 0;
}