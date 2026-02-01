#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    int m;
    cin >> m;
    int x = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int l1 = min(((a - 1 + x) % n) + 1, ((b - 1 + x) % n) + 1);
        int r1 = max(((a - 1 + x) % n) + 1, ((b - 1 + x) % n) + 1);
        int l2 = min(((c - 1 + x) % n) + 1, ((d - 1 + x) % n) + 1);
        int r2 = max(((c - 1 + x) % n) + 1, ((d - 1 + x) % n) + 1);

        int ans = 0;
        for (int j = l1; j <= r1; j++) {
            int num = p[j - 1];
            if (l2 <= pos[num] + 1 && pos[num] + 1 <= r2) {
                ans++;
            }
        }

        cout << ans << endl;
        x = ans + 1;
    }

    return 0;
}