#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&a](int x, int y) {
        return a[x] < a[y];
    });

    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        int pos = abs(i - idx[i]);
        for (int j = 0; j < n; j++) {
            if (!used[j] && abs(j - idx[i]) > pos) {
                used[j] = true;
                ans += 1LL * a[idx[i]] * abs(j - idx[i]);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}