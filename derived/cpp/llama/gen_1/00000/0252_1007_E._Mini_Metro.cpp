#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, k;
    cin >> n >> t >> k;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> ans(t, 0);
    for (int i = 0; i < t; ++i) {
        vector<ll> curr = a;
        for (int j = 0; j < n; ++j) {
            curr[j] += b[j] * (i + 1);
        }

        int trains = 0;
        ll cap = 0;
        for (int j = 0; j < n; ++j) {
            if (curr[j] > c[j]) {
                ll need = curr[j] - c[j];
                if (cap >= need) {
                    cap -= need;
                    curr[j] = c[j];
                } else {
                    need -= cap;
                    trains += (need + k - 1) / k;
                    cap = k - (need % k);
                    if (cap == k) cap = 0;
                    curr[j] -= need;
                }
            }

            if (cap == 0) {
                int take = min(curr[j], k);
                cap += k - take;
                curr[j] -= take;
            }
        }

        ans[i] = trains;
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}