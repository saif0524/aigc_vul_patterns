#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> friends[MAX_N];
int degrees[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        friends[x].push_back(y);
        friends[y].push_back(x);
        degrees[x]++;
        degrees[y]++;
    }

    vector<int> can_go(m);
    for (int i = 0; i < m; i++) {
        vector<bool> go(n, false);
        queue<int> q;
        for (int j = 0; j < n; j++) {
            if (degrees[j] < k) {
                q.push(j);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            go[x] = true;

            for (int y : friends[x]) {
                if (!go[y]) {
                    degrees[y]--;
                    if (degrees[y] < k) {
                        q.push(y);
                    }
                }
            }
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (!go[j]) {
                cnt++;
            }
        }
        can_go[i] = cnt;
    }

    vector<int> ans(m);
    ans[m - 1] = can_go[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        ans[i] = max(ans[i + 1], can_go[i]);
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}