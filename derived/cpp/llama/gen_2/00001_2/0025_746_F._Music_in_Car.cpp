#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int nw = 0; nw <= w; nw++) {
            long long sum_t = 0;
            long long sum_a = 0;
            int nw_now = nw;
            for (int i = x; i < n; i++) {
                if (nw_now == 0) {
                    sum_t += t[i];
                    sum_a += a[i];
                    if (sum_t > k) break;
                } else {
                    int tm = (t[i] + 1) / 2;
                    if (tm >= t[i] || t[i] > k - sum_t) {
                        sum_t += t[i];
                        sum_a += a[i];
                    } else {
                        sum_t += tm;
                        sum_a += a[i];
                        nw_now--;
                    }
                    if (sum_t > k) break;
                }
            }
            ans = max(ans, (int)sum_a);
        }
    }
    cout << ans << endl;
    return 0;
}