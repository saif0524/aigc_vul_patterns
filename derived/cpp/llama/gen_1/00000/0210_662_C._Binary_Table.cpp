#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> col(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col[j] += (s[i][j] == '1');
        }
    }

    vector<int> cnt(1 << n, 0);
    for (int j = 0; j < m; j++) {
        cnt[0] += min(col[j], n - col[j]);
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    count += (s[i][j] == '0');
                } else {
                    count += (s[i][j] == '1');
                }
            }
            sum += min(count, n - count);
        }
        cnt[mask] = sum;
    }

    int ans = *min_element(cnt.begin(), cnt.end());

    cout << ans << endl;

    return 0;
}