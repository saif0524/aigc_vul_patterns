#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, m;

vector<vector<int>> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    a.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> rmax(n), cmax(m);

    for (int i = 0; i < n; i++) {
        rmax[i] = *max_element(a[i].begin(), a[i].end());
    }

    for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i][j]);
        }
        cmax[j] = mx;
    }

    set<int> rset(rmax.begin(), rmax.end()), cset(cmax.begin(), cmax.end());

    vector<int> rnums, cnums;

    for (int i = n * m; i >= 1; i--) {
        if (rset.count(i)) rnums.push_back(i);
        if (cset.count(i)) cnums.push_back(i);
    }

    if (rnums.size() != rset.size() || cnums.size() != cset.size()) {
        cout << -1 << '\n';
        return 0;
    }

    int rptr = 0, cptr = 0;

    vector<vector<int>> ans(n, vector<int>(m, 0));

    while (rptr < rnums.size() && cptr < cnums.size()) {
        int rx = rnums[rptr], cx = cnums[cptr];

        if (rx == cx) {
            ans[rptr][cptr] = rx;
            rset.erase(rx);
            cset.erase(cx);
            rptr++, cptr++;
        } else if (rx > cx) {
            ans[rptr][cptr] = rx;
            rset.erase(rx);
            rptr++;
        } else {
            ans[rptr][cptr] = cx;
            cset.erase(cx);
            cptr++;
        }
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));

    queue<pair<int, int>> que;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j]) {
                que.push({i, j});
                used[i][j] = true;
            }
        }
    }

    int num = n * m;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        if (x + 1 < n && !used[x + 1][y]) {
            if (ans[x + 1][y] == 0) {
                num--;
                ans[x + 1][y] = num;
                used[x + 1][y] = true;
                que.push({x + 1, y});
            }
        }

        if (y + 1 < m && !used[x][y + 1]) {
            if (ans[x][y + 1] == 0) {
                num--;
                ans[x][y + 1] = num;
                used[x][y + 1] = true;
                que.push({x, y + 1});
            }
        }

        if (x - 1 >= 0 && !used[x - 1][y]) {
            if (ans[x - 1][y] == 0) {
                num--;
                ans[x - 1][y] = num;
                used[x - 1][y] = true;
                que.push({x - 1, y});
            }
        }

        if (y - 1 >= 0 && !used[x][y - 1]) {
            if (ans[x][y - 1] == 0) {
                num--;
                ans[x][y - 1] = num;
                used[x][y - 1] = true;
                que.push({x, y - 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }

    return 0;
}