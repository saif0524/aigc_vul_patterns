#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e3 + 10;

pii a[MAXN];

int ccw(pii a, pii b, pii c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int x1 = a[0].first, x2 = a[1].first, y1 = a[0].second;
    int ans = 0;

    for (int i = min(x1, x2); i <= max(x1, x2); i++) {
        bool ok = true;
        for (int j = 2; j < n; j++) {
            if (ccw({i, y1}, a[j], a[(j + 1) % n]) < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}