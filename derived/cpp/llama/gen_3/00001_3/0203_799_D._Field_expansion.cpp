#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;

    vector<int> extensions(n);
    for (int i = 0; i < n; i++) {
        cin >> extensions[i];
    }

    sort(extensions.begin(), extensions.end(), greater<int>());

    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        int nh = h, nw = w, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cnt++;
                if (nh <= nw) {
                    nh *= extensions[i];
                } else {
                    nw *= extensions[i];
                }
            }
        }
        if (nh >= a && nw >= b || nh >= b && nw >= a) {
            ans = min(ans, cnt);
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}