#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 50 + 10;

int dis[MAX_N][MAX_N];

int main() {
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dis[i][j] = numeric_limits<int>::max();
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = 1;
        dis[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] != numeric_limits<int>::max() && dis[k][j] != numeric_limits<int>::max()) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    vector<int> ans(k + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= k; i++) {
        pq.push({dis[a[i]][1], i});
    }

    long long res = 0;
    int sum = 0;
    while (!pq.empty()) {
        int t = pq.top().first;
        int id = pq.top().second;
        pq.pop();

        res += 1LL * c * t;
        sum++;
        ans[id] = t;

        res += 1LL * d * sum * sum;
    }

    cout << res << endl;

    return 0;
}