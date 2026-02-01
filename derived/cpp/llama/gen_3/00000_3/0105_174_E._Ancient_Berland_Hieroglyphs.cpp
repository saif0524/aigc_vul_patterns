#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1000005;

int n, m, ans;
vector<int> a, b;
unordered_map<int, int> pos;

int main() {
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < m; i++) pos[b[i]] = i;

    for (int i = 0; i < n; i++) {
        vector<int> cur;
        for (int j = i; j < i + n; j++) {
            int x = a[j % n];
            if (pos.find(x) != pos.end()) cur.push_back(pos[x]);
        }

        sort(cur.begin(), cur.end());
        int cnt = 0, mx = 0;
        for (int x : cur) {
            if (cnt == 0 || x != cur[cnt - 1] + 1) {
                cnt = 1;
            } else {
                cnt++;
            }
            mx = max(mx, cnt);
        }
        ans = max(ans, mx);
    }

    cout << ans << endl;

    return 0;
}