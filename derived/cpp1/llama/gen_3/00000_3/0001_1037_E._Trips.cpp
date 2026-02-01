#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> friendship(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friendship[i] = {x - 1, y - 1};
    }

    vector<unordered_map<int, int>> friends(n);
    vector<int> degree(n);

    for (int i = 0; i < m; i++) {
        friends[friendship[i][0]][friendship[i][1]] = 1;
        friends[friendship[i][1]][friendship[i][0]] = 1;
        degree[friendship[i][0]]++;
        degree[friendship[i][1]]++;
    }

    vector<int> ans(m);
    for (int i = m - 1; i >= 0; i--) {
        queue<int> q;
        vector<bool> del(n, false);
        for (int j = 0; j < n; j++) {
            if (degree[j] < k) {
                q.push(j);
                del[j] = true;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : friends[u]) {
                degree[v.first]--;
                if (!del[v.first] && degree[v.first] < k) {
                    q.push(v.first);
                    del[v.first] = true;
                }
            }
        }

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (!del[j]) count++;
        }

        ans[i] = count;

        if (i > 0) {
            friends[friendship[i - 1][0]][friendship[i - 1][1]] = 1;
            friends[friendship[i - 1][1]][friendship[i - 1][0]] = 1;
            degree[friendship[i - 1][0]]++;
            degree[friendship[i - 1][1]]++;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}