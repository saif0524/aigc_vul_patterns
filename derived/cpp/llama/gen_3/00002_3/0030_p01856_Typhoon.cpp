#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int h, w;
vector<vector<int>> d;

bool isvalid(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

bool isPossible(int si, int sj, int ti, int tj) {
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> dist(h, vector<int>(w, 1000000));
    vector<vector<int>> prev(h, vector<int>(2, -1));

    dist[si][sj] = 0;
    vector<pair<int, int>> q;
    q.push_back({si, sj});
    int di = 0;

    while (q.size() > 0) {
        int i = q[di].first;
        int j = q[di].second;
        q.erase(q.begin() + di);
        di = 0;

        if (i == ti && j == tj) {
            break;
        }

        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (isvalid(ni, nj) &&!seen[ni][nj]) {
                if (dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    prev[ni][0] = i;
                    prev[ni][1] = j;
                    q.push_back({ni, nj});
                }
            }
        }

        seen[i][j] = true;
    }

    if (prev[ti][0] == -1) {
        return false;
    }

    int ci = ti;
    int cj = tj;

    while (ci!= si || cj!= sj) {
        for (int x = ci - 1; x <= ci + 1; x++) {
            for (int y = cj - 1; y <= cj + 1; y++) {
                if (isvalid(x, y) && d[x][y] < d[ci][cj]) {
                    d[x][y]++;
                }
            }
        }

        ci = prev[ci][0];
        cj = prev[ci][1];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (d[i][j] > 3) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin >> h >> w;
    d.resize(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> d[i][j];
        }
    }

    for (int si = 0; si < h; si++) {
        for (int sj = 0; sj < w; sj++) {
            for (int ti = 0; ti < h; ti++) {
                for (int tj = 0; tj < w; tj++) {
                    if (10000 * ti + tj <= 10000 * si + sj) {
                        vector<vector<int>> temp = d;
                        if (isPossible(si, sj, ti, tj)) {
                            cout << si + 1 << " " << sj + 1 << " " << ti + 1 << " " << tj + 1 << endl;
                            return 0;
                        }
                        d = temp;
                    }
                }
            }
        }
    }

    return 0;
}