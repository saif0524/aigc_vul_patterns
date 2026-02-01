#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        vector<pair<int, int>> a(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[j].first >> a[j].second;
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x.second < y.second;
        });

        int c = 3;
        long long sum = 0;
        for (int j = k - 1; j >= 0; --j) {
            if (a[j].first <= c) {
                c -= a[j].first;
                sum += a[j].second;
            }
        }

        ans += sum;
        cnt += (sum > 0);

        if (cnt % 10 == 0 && cnt > 0) {
            if (i < n - 1) {
                int kk;
                cin >> kk;

                vector<pair<int, int>> aa(kk);
                for (int jj = 0; jj < kk; ++jj) {
                    cin >> aa[jj].first >> aa[jj].second;
                }

                sort(aa.begin(), aa.end(), [](auto &xx, auto &yy) {
                    return xx.second > yy.second;
                });

                if (aa[0].first <= 3) {
                    ans += aa[0].second;
                }
            } else if (k > 0) {
                sort(a.begin(), a.end(), [](auto &xx, auto &yy) {
                    return xx.second > yy.second;
                });

                if (a[0].first <= 3) {
                    ans += a[0].second;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}