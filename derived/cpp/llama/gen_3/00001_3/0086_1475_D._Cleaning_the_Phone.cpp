#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int t, n, m, a[MAXN], b[MAXN], sum[2], cnt[2];
vector<int> one, two;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        one.clear(), two.clear(), sum[0] = 0, sum[1] = 0, cnt[0] = 0, cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) one.push_back(a[i]), sum[0] += a[i], cnt[0]++;
            else two.push_back(a[i]), sum[1] += a[i], cnt[1]++;
        }
        sort(one.begin(), one.end(), cmp);
        sort(two.begin(), two.end(), cmp);
        int ans = INT_MAX;
        for (int i = 0; i <= cnt[0]; i++) {
            if (sum[0] - i * one[i % cnt[0]] >= m) ans = min(ans, i);
            else {
                int tmp = m - sum[0] + i * one[i % cnt[0]];
                int low = 0, high = cnt[1];
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (tmp <= i * one[i % cnt[0]] + mid * two[mid % cnt[1]]) high = mid;
                    else low = mid + 1;
                }
                if (low != cnt[1]) ans = min(ans, i + low);
            }
        }
        if (ans == INT_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }
}