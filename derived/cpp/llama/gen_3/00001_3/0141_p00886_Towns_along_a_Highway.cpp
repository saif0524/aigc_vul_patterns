#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 20;

int N;
int d[MAX_N * (MAX_N - 1) / 2];
int dist[MAX_N][MAX_N];
int ans[MAX_N];

void solve() {
    cin >> N;
    if (N == 0) return;
    int idx = 0;
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        cin >> d[i];
    }
    sort(d, d + N * (N - 1) / 2, greater<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = 0;
        }
    }
    idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            dist[i][j] = dist[j][i] = d[idx++];
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        for (int j = 0; j < N; j++) {
            if (i!= j) {
                tmp.push_back(j);
                vector<int> cur;
                for (int k = 0; k < N - 1; k++) {
                    cur.push_back(dist[tmp[k]][tmp[k + 1]]);
                }
                bool flag = true;
                for (int k = 0; k < N - 1; k++) {
                    for (int l = k + 1; l < N - 1; l++) {
                        if (cur[k] + cur[k + 1] > cur[l]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) {
                    res.push_back(cur);
                }
                tmp.pop_back();
            }
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

int main() {
    while (true) {
        solve();
    }
    return 0;
}