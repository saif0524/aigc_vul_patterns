#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 300 * 1000 + 10;

int n, x1, x2, c[maxN];
pair<int, int> a[maxN];

bool check(int k1, int k2) {
    int need1 = (x1 + k1 - 1) / k1;
    int need2 = (x2 + k2 - 1) / k2;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= need1) {
            cnt1++;
        }
        if (a[i].first >= need2) {
            cnt2++;
        }
    }

    return cnt1 >= k1 && cnt2 >= k2;
}

void solve() {
    scanf("%d %d %d", &n, &x1, &x2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        a[i] = {c[i], i + 1};
    }

    sort(a, a + n, greater<pair<int, int>>());

    for (int k1 = 1; k1 <= n; k1++) {
        for (int k2 = 1; k1 + k2 <= n; k2++) {
            if (check(k1, k2)) {
                vector<int> v1, v2;
                int need1 = (x1 + k1 - 1) / k1;
                int need2 = (x2 + k2 - 1) / k2;

                for (int i = 0; i < n; i++) {
                    if (v1.size() < k1 && a[i].first >= need1) {
                        v1.push_back(a[i].second);
                    } else if (v2.size() < k2 && a[i].first >= need2) {
                        v2.push_back(a[i].second);
                    }
                }

                printf("Yes\n");
                printf("%d %d\n", k1, k2);
                for (auto x : v1) printf("%d ", x);
                printf("\n");
                for (auto x : v2) printf("%d ", x);
                printf("\n");
                return;
            }
        }
    }

    printf("No\n");
}

int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}