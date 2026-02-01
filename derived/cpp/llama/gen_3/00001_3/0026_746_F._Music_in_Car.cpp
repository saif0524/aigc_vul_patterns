#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            int sum = 0, time = 0;
            for (int i = x; i < n; i++) {
                if (cnt > 0 && time + t[i] / 2 <= k) {
                    sum += a[i];
                    time += t[i] / 2;
                    cnt--;
                } else if (time + t[i] <= k) {
                    sum += a[i];
                    time += t[i];
                } else {
                    break;
                }
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}