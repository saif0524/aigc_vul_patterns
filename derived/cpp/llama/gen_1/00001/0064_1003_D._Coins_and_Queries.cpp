#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int b;
        cin >> b;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == (1 << i)) {
                    cnt++;
                }
            }
            int need = (b >> i) & 1;
            if (need > cnt) {
                if (cnt > 0) {
                    b -= cnt * (1 << i);
                    ans += cnt;
                } else {
                    break;
                }
            } else {
                b -= need * (1 << i);
                ans += need;
            }
        }
        if (b > 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}