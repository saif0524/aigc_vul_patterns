#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 5000 + 10;
const int MAXM = 20000 + 10;

int n, m;
int a[MAXM], b[MAXM];
vector<int> vec[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        vec[a[i]].push_back(b[i]);
    }

    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
        reverse(vec[i].begin(), vec[i].end());
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        queue<pii> q;
        vector<int> cnt(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            for (auto x : vec[j]) {
                if (x >= j) {
                    cnt[n - j + x] += 1;
                } else {
                    cnt[n - j + 1 + x] += 1;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (cnt[j]) q.push({i, j});
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            ans += (y - x + n) % n;
            if (vec[x].size() && vec[x].back() <= y) {
                auto z = vec[x].back();
                vec[x].pop_back();
                if (z != y) {
                    q.push({x, z});
                }
            }
        }
        cout << ans << " ";
    }
    return 0;
}