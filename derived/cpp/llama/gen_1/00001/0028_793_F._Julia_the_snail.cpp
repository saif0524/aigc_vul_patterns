#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> ropes(m);
    for (int i = 0; i < m; i++) {
        cin >> ropes[i].first >> ropes[i].second;
    }
    sort(ropes.begin(), ropes.end());

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int ans = x;
        for (int j = 0; j < m; j++) {
            if (ropes[j].first >= x && ropes[j].second <= y) {
                ans = max(ans, ropes[j].second);
                x = ropes[j].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}