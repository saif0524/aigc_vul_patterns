#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, M;
    cin >> n >> k >> M;

    vector<int> t(k);
    for (int i = 0; i < k; ++i) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<int> p(k + 1);
    for (int i = 1; i <= k; ++i) {
        p[i] = p[i - 1] + t[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k * i && j <= M; ++j) {
            int tmp = i * (k + 1);
            int tmpM = M - j;
            for (int l = 1; l <= n - i && tmpM >= 0; ++l) {
                int pos = upper_bound(p.begin(), p.end(), tmpM) - p.begin() - 1;
                if (pos < 0) break;
                tmp += pos;
                tmpM -= p[pos];
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << '\n';

    return 0;
}