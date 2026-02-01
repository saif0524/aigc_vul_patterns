#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<long long> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> cnt(n + 1, 0);
            for (int k = i; k <= j; ++k) {
                ++cnt[t[k]];
            }

            int mx = 0;
            int dominant = -1;
            for (int k = 1; k <= n; ++k) {
                if (cnt[k] > mx) {
                    mx = cnt[k];
                    dominant = k;
                }
            }

            ++ans[dominant - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}