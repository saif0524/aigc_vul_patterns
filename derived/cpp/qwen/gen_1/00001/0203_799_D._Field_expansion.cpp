#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> exts(n);
    for (int &x : exts) cin >> x;
    if (a > b) swap(a, b);
    if (h > w) swap(h, w);
    if (h >= a && w >= b) {
        cout << 0 << endl;
        return 0;
    }
    sort(exts.rbegin(), exts.rend());
    int ans = -1;
    int ah = h, aw = w;
    for (int i = 0; i < n; ++i) {
        ah *= exts[i];
        if (ah >= a && aw >= b) {
            ans = i + 1;
            break;
        }
        ah /= exts[i];
        aw *= exts[i];
        if (ah >= a && aw >= b) {
            ans = i + 1;
            break;
        }
        aw /= exts[i];
    }
    cout << ans << endl;
    return 0;
}